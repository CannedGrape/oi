#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long long line[100001],tz[100001],ans[100001],anss,n,rest;
void scan()
{
	//long long maxx=100000009;
	long long ts=0;
	scanf ("%d %d",&n,&rest);
	for (int i=1;i<=n;i++)
	{
		scanf ("%d",&line[i]);
		if (line[i]>0)
		{
			tz[i]+=line[i];
			}
	}
	tz[1]=ans[1]=line[1];
	ans[2]=tz[1]+ans[1];
	for (int i=3;i<=n;i++)
	{
		if (line[i]>0)	
			for (int j=i;j<=n;j++)
			{
				tz[j]+=line[i];
			}
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			ans[i]=max(ans[j]+tz[j],ans[i]);
		}
		anss=max(ans[i],anss);
	}
	/*for (int i=1;i<=n;i++)
	{
		printf ("%d %d\n",ans[i],tz[i]);
	} */
}
void sum()
{
	
}
void print()
{
	printf ("%d",anss%rest);
}
int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);	
	scan();
	sum();
	print();
	//system ("pause");
	return 0;
} 