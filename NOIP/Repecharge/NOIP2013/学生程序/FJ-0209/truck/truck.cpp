#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#define maxm 50010
#define maxn 10010
using namespace std;
struct road
{
	int st,end,weight,link;
};
int N,M,Q,MAXW=0;
road G[maxm*2];
int first[maxn];
int nowl=0;
void add(int X,int Y,int Z)
{
	G[++nowl].st=X;
	G[nowl].end=Y;
	G[nowl].weight=Z;
	G[nowl].link=first[X];
	first[X]=nowl;
}
int vis[maxn];
bool dfs(int k,int Y,int minW)
{
	if (k==Y) return true;
	int i,j,x;
	for (i=first[k];i;i=G[i].link)
	{
		if (G[i].weight<minW) continue;
		x=G[i].end;
		if (!vis[x])
		{
			vis[x]=true;
			if (dfs(x,Y,minW)) return true;
	    }
	}
	return false;
}
void solve(int X,int Y)
{
	int L=-1,R=MAXW,mid;
	while (L<=R)
	{
		  memset(vis,0,sizeof(vis));
	      mid=(L+R)/2;
	       //printf("[%d %d %d]\n",L,R,mid);
	      if (L==mid)
	      {
				if (dfs(X,Y,mid)) L=mid+1;
				else R=mid-1;
				continue;
		  }
	      if (dfs(X,Y,mid)) L=mid;
	      else R=mid-1;
	}
	if (R>=0) printf("%d\n",R);
	else printf("-1\n");
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&N,&M);
	int i,j,X,Y,Z;
	for (i=1;i<=M;i++)
	{
		scanf("%d%d%d",&X,&Y,&Z);
		MAXW=max(MAXW,Z);
		add(X,Y,Z);
		add(Y,X,Z);
    }
    scanf("%d",&Q);
    for (i=1;i<=Q;i++)
    {
		scanf("%d%d",&X,&Y);
		solve(X,Y);
    }
    return 0;
}
