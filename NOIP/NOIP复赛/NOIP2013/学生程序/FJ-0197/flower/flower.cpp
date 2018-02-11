#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#define N 100004
using namespace std;
int h[N],temp[N],ans=0,d=0,n;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%d",&h[i]);
}
bool pd()
{
	if (d==1||d==2)  return 1;
	bool fl=0;
	if (temp[2]>temp[1])  fl=1;
	if (fl)
	{
		for (int i=1;i<=d/2;i++)
		{
			if (temp[2*i]<=temp[2*i-1]||temp[2*i]<=temp[2*i+1]) return 0;
		}
	}
	else
	{
		for (int i=1;i<=d/2;i++)
		{
			if (temp[2*i]>=temp[2*i-1]||temp[2*i]>=temp[2*i+1]) return 0;
		}
	}
	return 1;
}
void dfs(int k)
{
	if (k==n+1)
	{
		if (pd())  if (d>ans)  ans=d;
	}
	else 
	{
		temp[++d]=h[k];
		dfs(k+1);
		d--;
		dfs(k+1);
	}
}
void work()
{
	dfs(1);
	printf("%d",ans);
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	init();
	work();
	return 0;
}
