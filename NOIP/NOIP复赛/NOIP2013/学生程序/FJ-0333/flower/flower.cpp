#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
const int Maxn = 101005;
int n,h[Maxn], ans;
int main() {
  freopen("flower.in","r",stdin); freopen("flower.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", h + i);
    int cnt = 0;
    
    h[n+1] = -1;
	for (int i = 1; i <= n; ++i) 
      if (h[i] != h[i + 1]) h[++cnt] = h[i];
    
	n = cnt;
	h[0] = h[n + 1] = -1;
    if (h[2] > h[1]) ans = 1; else ans = 0;
    if (h[n - 1] > h[n]) ++ans;
	for (int i = 1; i <= n; ++i) 
	  if (h[i] > h[i - 1] && h[i] > h[i + 1]) ++ans;
	    else 
	  if (h[i] < h[i - 1] && h[i] < h[i + 1]) ++ans;
	
	printf("%d", ans);
  fclose(stdin); fclose(stdout);
}
