#include<cstdio>
#include<algorithm>
using namespace std;

int w, n, a[30000];

int main(){
  freopen("group.in", "r", stdin);
  freopen("group.out", "w", stdout);
  scanf("%d%d", &w, &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int l = 0, r = n-1, cnt = 0;
  while(l < r) {
    cnt++;
    if(a[l] + a[r] <= w) l++;
    r--;
  }
  if(l == r) cnt++;
  printf("%d\n", cnt);
  return 0;
}
