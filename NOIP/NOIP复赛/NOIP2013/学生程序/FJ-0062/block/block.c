#include"stdio.h"
int n,i;
long long pre,now,ans;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
    scanf("%d",&n);
    scanf("%lld",&pre);
    ans=pre;
    for(i=2;i<=n;i++)
    {
		scanf("%lld",&now);
		if(now>pre)
		{
			ans=ans+now-pre;
		}
		pre=now;
	}
	printf("%lld",ans);
	return 0;
}
	

			
    
