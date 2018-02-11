//rp++
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdlib>
using namespace std;
int i,j,n,m,k,ans,l;
int a[100100];
void dfs(int x,bool z,int t)
{
	int i;
	for(i=x+1;i<=n;i++)
	{
	    if(z==true)
		{
			if(a[i]>a[x])
			{
				dfs(i,!z,t+1);
			}
		}	
		else
		{
			if(a[i]<a[x])
			{
				dfs(i,!z,t+1);
			}
		}
	}
	if(t>ans) ans=t;
	return ;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(n-i+1<ans) break;
		dfs(i,true,1);
		dfs(i,false,1);
	}
	cout<<ans<<endl;
	return 0;
}
