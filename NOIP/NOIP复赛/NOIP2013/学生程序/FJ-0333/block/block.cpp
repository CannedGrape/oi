#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
const int Maxn = 100005;
int n,ans,h[Maxn];
int main() {
  freopen("block.in","r",stdin); freopen("block.out","w",stdout);
   scanf("%d",&n);
   ++n; h[0] = 0;
   ans = 0;
   for (int i = 1; i < n; ++i) scanf("%d", h + i);
   for (int i = 1; i < n; ++i) ans += (h[i] > h[i - 1] ? h[i] - h[i - 1] : 0);
   printf("%d", ans);
  fclose(stdin); fclose(stdout);
}  
