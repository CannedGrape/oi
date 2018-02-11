#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#define N 1002
#define INF 999999999
using namespace std;

int x,y,z,cost[N][N],dist[N][N],i,j,n,m,k,p,qq;
bool bo[N];
queue<int> q;

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	memset(cost,-1,sizeof(cost));
	memset(dist,-1,sizeof(dist));
	scanf("%d%d",&n,&m);
	for (i=1; i<=m; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		cost[x][y]=max(cost[x][y],z);
		cost[y][x]=max(cost[y][x],z);
	}
	for (p=1; p<=n; p++)
	{
		dist[p][p]=INF;
		cost[p][p]=INF;
		memset(bo,false,sizeof(bo));
		while (!q.empty()) q.pop();
		q.push(p);
		bo[p]=true;
		while (!q.empty())
		{
			k=q.front(); q.pop(); bo[k]=false;
			for (i=1; i<=n; i++)
			if ((cost[k][i]>0) && (dist[p][i]<min(dist[p][k],cost[k][i])))
			{
				dist[p][i]=min(dist[p][k],cost[k][i]);
				if (!bo[i])
				{
					bo[i]=true;
					q.push(i);
				}
			}
		}
	}
	scanf("%d",&qq);
	for (i=1; i<=qq; i++) 
	{
		scanf("%d%d",&x,&y);
		cout << dist[x][y] << endl;
	}
	return 0;
}
