#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 100000 + 9;
int a[N],ans = 1,f[N][2],Max,c0[1000000 + 9],c1[1000000 + 9],n;
inline void add(int (&c)[1000000 + 9],int x,int num)
{
	for (; x <= Max; x += (x & (-x)))
		c[x] = std::max(c[x],num);
}
inline int query(int (&c)[1000000 + 9],int x)
{
	int res = 0;
	for (; x; x -= (x & (-x)))
		res = std::max(res,c[x]);
	return res;
}
void work(const int (&a)[N])
{
	memset(f,0,sizeof f);
	memset(c0,0,sizeof c0);
	memset(c1,0,sizeof c1);
	f[1][0] = f[1][1] = 1;
	add(c0,Max - a[1] + 1,1);
	add(c1,a[1],1);
	for (int i = 2; i <= n; ++i) {
		f[i][0] = query(c1,a[i] - 1) + 1;
		f[i][1] = query(c0,Max - a[i]) + 1;
		add(c0,Max - a[i] + 1,f[i][0]);
		add(c1,a[i],f[i][1]);
		ans = std::max(ans,f[i][0]);
		ans = std::max(ans,f[i][1]);
	}
	//for (int i = 1; i <= n; ++i) printf("%d %d\n",f[i][0],f[i][1]);	puts("");
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",a + i);
		++a[i];
		Max = std::max(Max,a[i]);
	}
	work(a);
	//for (int i = 1; i <= n; ++i) a[i] = Max - a[i] + 1;
	//work(a);
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
}
