#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int a[1000001][4],n,p,maxn=-1000000000,mink=1000000000;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{cin>>a[i][1];}
	a[1][2]=a[1][1];a[1][3]=a[1][1];
	for(int i=2;i<=n;i++)
	{
		bool m=true;
		for(int j=1;j<=i;j++)
		{
			if(a[j][1]>0){a[i][2]+=a[j][1];m=false;}
			if(a[j][1]<mink)mink=a[j][1];
		}
		if(m)a[i][2]=mink;
		for(int j=1;j<i;j++)
		{
			if((a[j][2]+a[j][3])>maxn)maxn=(a[j][2]+a[j][3]);
		}
		a[i][3]=maxn;
	}
	maxn=-1000000000;
	for(int i=1;i<=n;i++)
	{
		if(a[i][3]>maxn)maxn=a[i][3];
	}
	printf("%d\n",maxn%p);
	return 0;
}
