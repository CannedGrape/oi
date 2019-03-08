#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long c[1000002][5],pl[1000002];
int main()
{
	int n,Max;
	long long p;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf(" %d%lld",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf(" %lld",&c[i][1]);
		pl[i]=pl[i-1]+c[i][1];
	}
	c[1][2]=c[1][1];
	for(int i=2,m;i<=n;i++)
	{
		m=-1000;
		for(int j=0;j<i;j++)
		{
			for(int k=j+1;k<=i;k++)
			{
				if(m<pl[k]-pl[j]) m=pl[k]-pl[j];
			}
		}
		c[i][2]=m;
	}
	c[1][3]=c[1][2],Max=c[1][3];
	for(int i=2,m;i<=n;i++)
	{
		m=-1000;
		for(int j=1;j<i;j++)
		{
			if(m<c[j][2]+c[j][3]) m=c[j][2]+c[j][3];
		}
		c[i][3]=m;
		if(c[i][3]>Max)Max=c[i][3];
	}
	cout<<Max%p<<endl;
	return 0;
}
