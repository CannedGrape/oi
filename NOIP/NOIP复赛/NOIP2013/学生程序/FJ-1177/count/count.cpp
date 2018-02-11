#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,x;
long long ans;
int pd(int s)
{
	while(s)
	{
		int z=s%10;
		s/=10;
		if(z==x)
		   ans++;
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		pd(i);
		}
	printf("%I64d\n",ans);
	return 0;
}
