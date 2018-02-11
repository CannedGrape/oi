#include <cstdio>
#include <cstring>
#include <algorithm>
const int MOD = 99999997,N = 100000 + 9;
int a[N],b[N],c[N],tmp[N],Map[N],n;
int query(int x)
{
	int res = 0;
	for (; x; x -= (x & (-x)))
		res += c[x];
	return res;
}
void add(int x)
{
	for (; x <= n; x += (x & (-x)))
		c[x] += 1;
}
int main()
{
	freopen("match.in","r",stdin); freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {scanf("%d",a + i);tmp[i] = a[i];}
	std::sort(tmp + 1,tmp + 1 + n);
	for (int i = 1; i <= n; ++i) a[i] = std::lower_bound(tmp + 1,tmp + 1 + n,a[i]) - tmp;
	for (int i = 1; i <= n; ++i) {scanf("%d",b + i);tmp[i] = b[i];}
	std::sort(tmp + 1,tmp + 1 + n);
	for (int i = 1; i <= n; ++i) b[i] = std::lower_bound(tmp + 1,tmp + 1 + n,b[i]) - tmp;
	for (int i = 1; i <= n; ++i) Map[b[i]] = i;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = Map[a[i]];
		//printf("%d ",query(n - a[i] + 1));
		(ans += query(n - a[i] + 1)) %= MOD;
		add(n - a[i] + 1);
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
}
