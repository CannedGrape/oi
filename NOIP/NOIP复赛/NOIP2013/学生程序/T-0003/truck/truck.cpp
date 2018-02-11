#include<iostream>
#include<cmath>
#include<stdio.h>
#include<cstdio>
using namespace std;
int check[5003][5003];
int a[30003],b[30003];
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int i,j;
	int n,m;
	int x,y,z;
	int q;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x>y) check[y][x]=z;
		else check[x][y]=z;
	}
	
	for(i=1;i<n;i++)
	for(j=i+1;j<=n;j++)
	{		
		check[i][j]=max(check[i][j],min(check[j-1][j],check[i][j-1]));
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(i=1;i<=q;i++)
	{
		if(check[a[i]][b[i]]!=0)
		printf("%d\n",check[a[i]][b[i]]);
		else printf("-1\n");
	}
	return 0;
}
