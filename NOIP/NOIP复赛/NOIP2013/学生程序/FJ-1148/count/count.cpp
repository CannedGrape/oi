#include<iostream>
#include<cstdio>
using namespace std;
int n,x,ans,i,r;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		r=i;
		while(r>0)
		{
			if(r%10==x)ans++;
			r/=10;
		}
	}
	printf("%d\n",ans);
	return 0;
}  
