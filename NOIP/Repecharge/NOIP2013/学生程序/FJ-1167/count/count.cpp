#include<cstdio>
#include<cstdlib>
using namespace std;
int n,x,ans=0;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		int ii=i,j=1;
		while(ii/10!=0)
		{
			ii/=10;
			j++;
		}
		ii=i;
		for(int k=1;k<=j;k++,ii/=10)
			if(ii%10==x)ans++;
	}
	printf("%d\n",ans);
	return 0;
}
