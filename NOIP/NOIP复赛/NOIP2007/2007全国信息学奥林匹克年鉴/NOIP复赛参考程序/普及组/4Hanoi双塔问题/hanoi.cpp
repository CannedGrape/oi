#include<iostream>
#include<cstdio>
using namespace std;
#define REP(i,n) for(int i = 0; i < (n); i++)

const int maxn = 100;
struct bign{
  int len, s[maxn];
  bign() { memset(s, 0, sizeof(s)); len = 1; }
  bign(const char* num) { *this = num; }
  bign operator = (const char* num) {
    len = strlen(num);
    REP(i,len) s[i] = num[len-i-1]-'0';
  }
  string str() {
    string res = "";
    REP(i,len) res = (char)(s[i] + '0') + res;
    return res;
  }
  void clean() {
    while(len>1 && !s[len-1]) len--;
  }
  bign operator * (const bign& b) {
    bign c; c.len = len+b.len;
    REP(i,len) REP(j,b.len) c.s[i+j] += s[i]*b.s[j];
    REP(i,c.len-1){ c.s[i+1] += c.s[i]/10; c.s[i] %= 10; }
    c.clean();
    return c;
  }
  bign operator - (const bign& b) {
    bign c; c.len = 0;
    for(int i = 0, g = 0; i < len; i++) {
      int x = s[i] - g;
      if(i < b.len) x -= b.s[i];
      if(x >= 0) g = 0; else { g = 1; x += 10; }
      c.s[c.len++] = x;
    }
    c.clean();
    return c;
  }
};

int main(){
  freopen("hanoi.in", "r", stdin);
  freopen("hanoi.out", "w", stdout);
  int n;
  cin >> n;
  bign ans = "1";
  REP(i,n+1) ans = ans * "2";
  cout << (ans - "2").str() << endl;
  return 0;
}
