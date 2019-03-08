#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[1001],b[1001][1001],c[1001];
int main()
{
	int n,m,i,j,ans=1;
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>a[i];
		for(j=1;j<=a[i];j++)
		{
			cin>>b[i][j];
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=a[i];j++)
		{
			if(c[b[i][j]]==0)
			{
				c[b[i][j]]++;
				if(i>0) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
