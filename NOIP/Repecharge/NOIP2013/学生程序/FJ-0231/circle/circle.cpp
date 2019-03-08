#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,x,ans,a,j;
int main()
{
	int i,po=1;
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	i=m;j=1;
	while(i!=0)
	{
		i+=m;i%=n;j++;
    }
    if(10%j==0) ans=x;
    else 
	{
		for(i=1;i<=k;i++) po*=10;
		if(po%j==0) ans=x;
		else 
		{
		a=(po%j)*m;
	    ans=(a+x)%n; 
	    }
	}
	printf("%d\n",ans);
	return 0;
}
