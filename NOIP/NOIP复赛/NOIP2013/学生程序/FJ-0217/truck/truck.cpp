#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>

using namespace  std;

const int MAXN=10100;
const int MAXM=50100;
const int MAX=100010;

struct node_edge
{
	int p,next,w;
}edge[3*MAXM];

int head[MAXN]; 
int n,m,k,num,start,end,ans;
queue <int> q;
bool visited[MAXN];

bool pd(int mid)
{
	int i,j;
	
	q.push(start);
	visited[start]=1;
	
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		
		if (u==end) return 1;
		
		int ed=head[u];
		while (ed!=0)
		{
			int v=edge[ed].p,w=edge[ed].w;
			
			if (w>=mid)
			{
			   if (!visited[v])
			   {
				   q.push(v);
				   visited[v]=1;
				}
			}
			ed=edge[ed].next;
		}
	}
	
	return 0;
}

int work()
{
	int l,r,mid;
	bool flag=0;
	
	l=0; 
	r=MAX;
	while (l<r)
	{
		memset(visited,0,sizeof(visited));
		mid=(l+r+1)/2;
		if (pd(mid)) { l=mid; flag=1;}
		else r=mid-1;
	}
    if (flag) return l;
    else return -1;
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	
	int i,j;
	
	num=0;
	scanf("%d%d",&n,&m);
	for (i=1; i<=m; i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		
		num++;
		if (head[u]==0) head[u]=num;
		else
		{
			edge[num].next=head[u];
			head[u]=num;
		}
		edge[num].p=v;
		edge[num].w=w;
		
		num++;
		if (head[v]==0) head[v]=num;
		else
		{
			edge[num].next=head[v];
			head[v]=num;
		}
		edge[num].p=u;
		edge[num].w=w;
	}
	
	scanf("%d",&k);
	for (i=1; i<=k; i++)
	{
		scanf("%d%d",&start,&end);
		
		ans=work();
		printf("%d\n",ans);
	}
	
	return 0;
}
