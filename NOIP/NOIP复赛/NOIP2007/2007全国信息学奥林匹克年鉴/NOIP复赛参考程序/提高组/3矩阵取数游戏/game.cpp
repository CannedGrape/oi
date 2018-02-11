#include<cstdio>
#include<iostream>
using namespace std;
#define REP(i,n)   for(int i = 0; i < (n); i++)

const int maxn = 200;
struct bign{
  int len, s[maxn];
  bign() { memset(s, 0, sizeof(s)); len = 1; }
  bign(const char* num) { *this = num; }
  bign operator = (const char* num) {
    len = strlen(num);
    REP(i,len) s[i] = num[len-i-1]-'0';
  }
  string str() const{
    string res = "";
    REP(i,len) res = (char)(s[i] + '0') + res;
    if(res == "") res = "0";
    return res;
  }
  void clean() {
    while(len>1 && !s[len-1]) len--;
  }
  bign operator + (const bign& b) {
    bign c; c.len = 0;
    for(int i = 0, g = 0; g || i < max(len,b.len); i++){
      int x = g;
      if(i < len) x += s[i];
      if(i < b.len) x += b.s[i];
      c.s[c.len++] = x%10; g=x/10;
    }
    return c;
  }
  bign operator * (const bign& b) {
    bign c; c.len = len+b.len;
    REP(i,len) REP(j,b.len) c.s[i+j] += s[i]*b.s[j];
    REP(i,c.len-1){ c.s[i+1] += c.s[i]/10; c.s[i] %= 10; }
    return c;
  }
  bool operator < (const bign& b) {
    if(len != b.len) return len < b.len;
    for(int i = len-1; i >= 0; i--)
      if(s[i] != b.s[i]) return s[i] < b.s[i];
    return false;
  }
  bign operator += (const bign& b) {
    *this = *this + b;
  }
  void operator >?= (const bign& b) {
    if (*this < b) *this = b;
  }
};

int n, m;
bign a[99],p[99],d[99][99], ans = "0";

int main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  cin >> n >> m;
  p[0] = "1";
  REP(i,m) p[i+1] = p[i] * "2";
  REP(i,n){
    string x; REP(j,m) { cin >> x; a[j] = x.c_str(); }
    REP(len,m+1) REP(st,m) if(!len) d[st][len] = "0"; else{
      if(st + len > m) break;
      bign w = p[m-len+1];
      d[st][len] = d[st+1][len-1] + a[st] * w;
      d[st][len] >?= d[st][len-1] + a[st+len-1] * w; 
    }
    ans += d[0][m];
  }
  cout << ans.str() << endl;
  return 0;
}
