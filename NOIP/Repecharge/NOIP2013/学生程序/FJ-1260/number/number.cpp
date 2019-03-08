#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
float a[10000001][3];
int main()
{
	memset(a[1],0,sizeof(a[1]));
	memset(a[2],0,sizeof(a[2]));
	int n,p,max;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0];
	}
	for(int i=1;i<=n;i++)
	{
		for(int y=1;y<=i;y++)
		{
			if(a[y][0]>0)
			a[i][1]+=a[y][0];
		}
		if(a[i][1]==0)
		{
			max=a[1][0];
			for(int y=1;y<=i;y++)
			{
				if(a[y][0]>max)
				max=a[y][0];
			}
			a[i][1]+=max;
		}
	}
	a[1][2]=a[1][1];
	max=a[1][2];
	for(int i=2;i<=n;i++)
	{
			max=(a[1][1]+a[1][2]);
			for(int y=1;y<i;y++)
			{
				if((a[y][1]+a[y][2])>max)
				max=(a[y][1]+a[y][2]);
			}
			a[i][2]+=max;
	}
	max=a[1][2];
	for(int i=2;i<=n;i++)
	{
		if(a[i][2]>max)
		{
			max=a[i][2];
		}
	}
	max=max%p;
	cout<<max;
	fclose(stdin);
	fclose(stdout);
	return(0);
}
