#include <cstdio>
#include <algorithm>
#include <cstring>
int n,ans,a[105],b[105],c[105];
typedef long long ll;
ll min;
bool visit[105];
int count(int st) {
	int s = 0,x = st; visit[st] = true;
	while (c[x] != st) {
		x = c[x]; visit[x] = true;
		++s;
	}
	return s;
}
void check() {
	ll s = 0;
	for (int i = 1; i <= n; ++i) {
		ll t = a[i] - b[c[i]];
		s += t * t;
	}
	if (s < min) min = s,ans = n;
	if (s == min) {
		int t = 0;
		for (int i = 1; i <= n; ++i) visit[i] = false; 
		for (int i = 1; i <= n; ++i)
			if (!visit[i]) t += count(i);
		if (t < ans) ans = t;
	}  
}
void dfs(int step) {
	if (step == n + 1) {
		check();
		return;
	}
	for (int i = 1; i <= n; ++i) 
		if (!visit[i]) {
			visit[i] = true;
			c[step] = i;
			dfs(step + 1);
			visit[i] = false;
		}
}
int main() {
	freopen("match.in","r",stdin); freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) scanf("%d",a + i);
	for (int i = 1; i <= n; ++i) scanf("%d",b + i);
	min = static_cast<ll>(1) << 61;
	dfs(1);
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
}
