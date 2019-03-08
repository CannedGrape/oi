#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int map[100010];
int next[100010];
int new_map[100010];
int n;
int ans;

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);	
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&map[i]);
	}
	map[n+1]=-1;
	for (i=1;i<=n;i=j)
	{	
		j=i+1;
		while(map[i]==map[j])
		{
			j++;
		}
		next[i]=j;
	}
	j=1;
	for(i=1;i<=n;i=next[i])
	{
		new_map[j]=map[i];
		j++;
	}
	n=j-1;
	if(n==1)
	{
		ans=1;
	}
	else
	{
		ans=2;
	}
	for(i=2;i<=n-1;i++)
	{
		if((new_map[i]<new_map[i-1])&&(new_map[i]<new_map[i+1]))
		{
			ans++;
		}
		if((new_map[i]>new_map[i-1])&&(new_map[i]>new_map[i+1]))
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
