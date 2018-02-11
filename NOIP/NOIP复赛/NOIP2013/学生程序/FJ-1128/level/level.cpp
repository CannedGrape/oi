#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n,m,N,a,aa;
bool b[1001][1001],flag[1001];
long long sum;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&N,&a);
		for(int j=2;j<=N;j++)scanf("%d",&aa),b[a][aa]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)flag[j]=0;
	    for(int j=1;j<=n;j++)
	    {
		    if(b[j][i])flag[j]=1;
		}
		for(int j=1;j<=n;j++)
		{
			if(flag[j])
			{
			    for(int k=j;k<=n;k++)
			        if(flag[k] && (b[k][j] || b[j][k]))sum++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
