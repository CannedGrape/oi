#include<cstdio>
using namespace std;

int n,p,t[1000001],ans=-2147483647;

int main()
{
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1,y,u;i<=n;++i)
	{
	  scanf("%d",t+i);y=-2147483647;
	  int p=1,q=2,sum=t[1];
	  for(;p<q;) if((q<=i)&&(t[q]>0)) sum+=t[q++];else {y=y>sum?y:sum;sum-=t[p++];}
	  if(i==1) u=y;ans=ans>u?ans:u;u=ans+y;
	}
	printf("%d",ans%p);
	return 0;
}
