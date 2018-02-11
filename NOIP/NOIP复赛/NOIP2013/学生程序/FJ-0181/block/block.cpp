#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int map[100010];
int f[100010];
int n;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&map[i]);
	}
	f[1]=map[1];
	for(i=2;i<=n;i++)
	{
		if(map[i]<=map[i-1])
		{
			f[i]=f[i-1];
		}
		else
		{
			f[i]=f[i-1]+map[i]-map[i-1];
		}
	}
	printf("%d\n",f[n]);
	return 0;
}
