#include <cstdio>
#include <algorithm>
typedef long long LL;
const int N = 100010;
const int MOD = 99999997;
int n, ans, tmp, b[N];
bool ok[N];
struct Info {
	int a, b;
} s[N];
inline bool cmpa(const Info &lhs, const Info &rhs) { return lhs.a < rhs.a; }
inline int Find(const int x)
{
	int lef = 0, rig = n+1;
	while (lef + 1 < rig) {
		const int mid = (lef + rig) >> 1;
		if (b[mid] == x) return mid;
		(b[mid] < x ? lef : rig) = mid;
	}
	return rig;
}
int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &s[i].a);
	
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &s[i].b);
		b[i] = s[i].b;
	}
	std::sort(b+1, b+1+n);
	std::sort(s+1, s+1+n, cmpa);
	
	for (int i = 1; i <= n; ++i) {
		if (ok[i]) continue;
		const int fd = Find(s[i].b);
		if (i == fd) {
			ok[i] = true;
			continue;
		}
		const int fdd = Find(s[fd].b);
		if (fdd == i) {
			++ans;
			ok[fd] = ok[fdd] = true;
			continue;
		}
	}
	bool flag = false;
	for (int i = 1; i <= n; ++i)
		if (!ok[i]) {
			++ans;
			flag = true;
		}
	if (flag) --ans;
	printf("%d\n", ans%MOD);
}
