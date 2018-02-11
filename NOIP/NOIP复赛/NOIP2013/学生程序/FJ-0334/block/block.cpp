#include <cstdio>
const int N = 100010;
int n, h[N], st, ed, ans;
int Work(const int st, const int ed)
{
	int res = 0;
	if (st == ed) {
		res = h[st];
		h[st] = 0;
		return res;
	}
	int mini = 0x7F7F7F7F;
	for (int i = st; i <= ed; ++i)
		if (h[i] < mini) mini = h[i];
//	if (mini == 0x7F7F7F7F) {
	//	puts("aaaa  ");
	//	for (int i = st; i <= ed; ++i)
	//		printf("%d %d", st, ed);
	//	puts("");
//	}
	
	int x = st, y;
	for (int i = st; i <= ed; ++i) h[i] -= mini;
	
//		if (st == 25315 && ed == 25320) {
//		for (int i = st; i <= ed; ++i)
//			printf("%d ", h[i]);
//			puts("");
//	}
	
	while (h[x] == 0 && x <= ed) ++x;
	for (int i = x; i <= ed; ++i) {
		if (h[i] == 0 && h[i-1] != 0) {
			y = i-1;
//			if (x > y) printf("zz %d %d %d %d\n", x, y, st, ed);
			res += Work(x, y);
			x = i+1;
			while (h[x] == 0 && x <= ed) ++x;
			if (x > ed) return res+mini;
		}
	}
	if (x <= ed) res += Work(x, ed);
	return res+mini;
}
int main()
{
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", h+i);
	st = 1;
	while (h[st] == 0 && st <= n) ++st;
	for (int i = st; i <= n; ++i) {
		if (h[i] == 0 && h[i-1] != 0) {
			ed = i-1;
			ans += Work(st, ed);
			st = i+1;
			while (h[st] == 0 && st <= n) ++st;
		}
	}
	if (st <= n) ans += Work(st, n);
	printf("%d\n", ans);
}
