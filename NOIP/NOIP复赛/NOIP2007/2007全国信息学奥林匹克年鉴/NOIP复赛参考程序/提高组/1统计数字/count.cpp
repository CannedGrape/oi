#include<map>
#include<cstdio>
#define FOREACH(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
using namespace std;

map<int,int> cnt;
int main(){
  freopen("count.in", "r", stdin);
  freopen("count.out", "w", stdout);
  int n, a;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a);
    cnt[a]++;
  }
  FOREACH(i,cnt)
    printf("%d %d\n", i->first, i->second);
  return 0;
}
