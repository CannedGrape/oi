#include <cstdio>
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int n;
	scanf("%d",&n);
	int x,y = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&x);
		if (x > y) ans += x - y;
		y = x;
	}
	//printf("%I64d\n",ans);
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
}
