#include<cstdio>
int n,ans;
int h[100010];
int main()
{
	int i;
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",h+i);
	for(i=1;i<=n;++i)
		if(h[i]-h[i-1]>0)
			ans+=h[i]-h[i-1];
	printf("%d\n",ans);
	return 0;
}
