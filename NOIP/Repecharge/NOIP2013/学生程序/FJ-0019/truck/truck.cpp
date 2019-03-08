#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define MAXN 100010
using namespace std;
struct edge
{
	int x,y,dis;
}map[MAXN];
int n,m,q,fa[MAXN],to[MAXN],next[MAXN],p[MAXN],c[MAXN],tail;
int dep[MAXN],mul[22],f[MAXN][20],g[MAXN][20];
bool vis[MAXN];
bool cmp(edge a1,edge b1) {return a1.dis>b1.dis;}
int find(int k)
{
	if (fa[k]!=k) fa[k]=find(fa[k]);
	return fa[k];
}
void add(int u,int v,int w)
{
	to[++tail]=v; next[tail]=p[u]; p[u]=tail; c[tail]=w;
}
void dfs(int now)
{
	vis[now]=1;
	int i;
	for (i=1;f[f[now][i-1]][i-1];++i)
	{
		f[now][i]=f[f[now][i-1]][i-1];
		g[now][i]=min(g[now][i-1],g[f[now][i-1]][i-1]);
	}
	for (i=p[now];i;i=next[i])
		if (!vis[to[i]])
		{
			dep[to[i]]=dep[now]+1;
			f[to[i]][0]=now;
			g[to[i]][0]=c[i];
			dfs(to[i]);
		}
}
void LCA(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	int i,ans=MAXN;
	while (dep[x]>dep[y])
	{
		for (i=0;dep[y]+mul[i]<=dep[x];++i);
		--i;
		ans=min(ans,g[x][i]);
		x=f[x][i];
	}
	while (x!=y && f[x][0]!=f[y][0])
	{
		for (i=1;f[x][i]!=f[y][i];++i);
		--i;
		ans=min(ans,g[x][i]);
		ans=min(ans,g[y][i]);
		x=f[x][i];
		y=f[y][i];
	}
	if (x!=y)
		ans=min(g[x][0],ans),ans=min(ans,g[y][0]);
	printf("%d\n",ans);
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;++i)
		scanf("%d%d%d",&map[i].x,&map[i].y,&map[i].dis);
	for (i=1,j=m+1;i<=n;++i,++j)
	{
		map[j].x=n+1;
		map[j].y=i;
		map[j].dis=-1;
	}
	m=m+n;
	sort(map+1,map+1+m,cmp);
	for (i=1;i<=n+1;++i)
		fa[i]=i;
	for (i=1;i<=m;++i)
		if (find(map[i].x)!=find(map[i].y))
		{
			fa[find(map[i].x)]=find(map[i].y);
			add(map[i].x,map[i].y,map[i].dis);
			add(map[i].y,map[i].x,map[i].dis);
		}
	mul[0]=1;
	for (i=1;i<=20;++i)
		mul[i]=mul[i-1]<<1;
	memset(g,200,sizeof(g));
	dep[n+1]=1; 
	dfs(n+1);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%d",&i,&j);
		LCA(i,j);
	}
	//system("pause");
	return 0;
}
