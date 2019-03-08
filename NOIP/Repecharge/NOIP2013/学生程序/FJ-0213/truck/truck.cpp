#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
int n,m,k,x,y,z;
int map[1001][1001],w[1001][1001];
int i,j,tot=1000;
int q,head,tail,s,e;
int que[10000];
int ans[1001];
bool f[1001];
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	cin>>n>>m;
	for (i=0;i<=1000;i++)
	    for (j=0;j<=1000;j++)
	    {
	        map[i][j]=0;
	        w[i][j]=0;
	    }
	for (i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if (z>map[x][y]){map[x][y]=z; map[y][x]=z;}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		    if (map[i][j]>0)
		    {
				map[i][0]++;
				w[i][map[i][0]]=map[i][j];
				map[i][map[i][0]]=j;
			}
	}
	cin>>q;
	for (i=1;i<=q;i++)
	{
		for (j=0;j<=1000;j++)f[j]=false;
		for (j=0;j<=1000;j++)ans[j]=-1;
		cin>>s>>e;
		ans[s]=1000000;
		f[s]=true;
		head=0;
		tail=1;
		que[1]=s;
		while (head<tail)
		{
			head++;
			//cout<<que[head]<<' ';
			for (j=1;j<=map[que[head]][0];j++)
			{
				if (min(w[que[head]][j],ans[que[head]])>ans[map[que[head]][j]])
				{
				   ans[map[que[head]][j]]=min(w[que[head]][j],ans[que[head]]);
				   if (f[map[que[head]][j]]==false)
				   {
						tail++;
				        que[tail]=map[que[head]][j];
				        f[que[tail]]=true;
				   }
				}
			}
			f[que[head]]=false;
		}
		cout<<ans[e]<<endl;
	}
}
/*
7 10
1 2 3
2 3 5
1 3 4
3 4 4
4 5 7
5 6 5
2 6 2
6 2 3
6 7 3
7 5 2
10000
*/
