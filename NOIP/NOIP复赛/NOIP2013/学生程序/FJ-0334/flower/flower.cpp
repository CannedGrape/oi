#include <cstdio>
#include <algorithm>
const int N = 100010, INF = 0x7F7F7F7F;
int n, h[N], f[2][N], g[2][N], ans;
int main()
{
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", h+i);
		f[0][i] = f[1][i] = 0;
	}
	g[0][0] = INF, g[1][0] = 0;
	for (int i = 1; i <= n; ++i) {
		g[0][i] = g[0][i-1];
		g[1][i] = g[1][i-1];
		f[0][i] = f[0][i-1];
		f[1][i] = f[1][i-1];
		if (f[0][i-1] & 1) {
			if (h[i] > g[0][i-1]) {
				if (f[0][i-1]+1 > f[0][i]) {
					f[0][i] = f[0][i-1] + 1;
					g[0][i] = h[i];
				}
			}
		} else {
			if (h[i] < g[0][i-1]) {
				if (f[0][i-1]+1 > f[0][i]) {
					f[0][i] = f[0][i-1] + 1;
					g[0][i] = h[i];
				}
			}
		}
		if (f[1][i-1] & 1) {
			if (h[i] < g[1][i-1]) {
				if (f[1][i-1]+1 > f[1][i]) {
					f[1][i] = f[1][i-1] + 1;
					g[1][i] = h[i];
				}
			}
		} else {
			if (h[i] > g[1][i-1]) {
				if (f[1][i-1]+1 > f[1][i]) {
					f[1][i] = f[1][i-1] + 1;
					g[1][i] = h[i];
				}
			}
		}
	}
	
	
	for (int i = 1; i <= n; ++i)
		ans = std::max(ans, std::max(f[0][i], f[1][i]));
	printf("%d\n", ans);
} 
