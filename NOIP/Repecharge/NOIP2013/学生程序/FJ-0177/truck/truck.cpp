#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF=10000005;

int n,m,tot,q;
int fa[10005],l[10005],r[10005],lw[10005],rw[10005],deep[10005],faw[10005],fan[10005];
bool visit[10005];
int faq[10005][25],wei[10005][25];

struct orz
{
	int x,y,w;
} e[50005];

bool cmp(orz a,orz b) 
{
	return a.w>b.w;
}

int get(int v)
{
	if (v==fa[v]) return v;
	else return fa[v]=get(fa[v]);
}

void add_edge(int v)
{
	if (l[e[v].x]==0) 
	{
		l[e[v].x]=e[v].y;
		lw[e[v].x]=e[v].w;
	}
	else
	{
		r[e[v].x]=e[v].y;
		rw[e[v].x]=e[v].w;
	}
	if (l[e[v].y]==0) 
	{
		l[e[v].y]=e[v].x;
		lw[e[v].y]=e[v].w;
	}
	else
	{
		r[e[v].y]=e[v].x;
		rw[e[v].y]=e[v].w;
	}
}

void dfs(int k)
{
	deep[k]=tot++;
	if (!visit[l[k]]) 
	{
		visit[l[k]]=1;
		fan[l[k]]=k;
		faw[l[k]]=lw[k];
		dfs(l[k]);
	}
	if (!visit[r[k]]) 
	{
		visit[r[k]]=1;
		fan[r[k]]=k;
		faw[r[k]]=rw[k];
		dfs(r[k]);
	}
}

int my_min(int x,int y)
{
	if (x<y) return x;
	else return y;
}

void sb()
{
	int i,j;
	for (i=1;i<=n;++i) 
	{
		faq[i][0]=fan[i];
		wei[i][0]=faw[i];
	}
	for (i=1;i<=n;++i)
		for (j=1;(1<<j)<=n;++j)
		{
			faq[i][j]=faq[faq[i][j-1]][j-1];
			wei[i][j]=my_min(wei[i][j-1],wei[faq[i][j-1]][j-1]);
		}
}

int lca(int u,int v)
{
	int ans=INF,i;
	if (get(u)!=get(v)) return -1;
	while (deep[u]<deep[v])
	{
		for (i=0;(1<<i)<=n;++i)
		if (deep[faq[v][i]]<=deep[u]) break;
		ans=my_min(ans,wei[v][i]);
		v=faq[v][i];
		if (deep[u]==deep[v]) break;
		for (i=0;(1<<i)<=n;++i)
		if (deep[faq[u][i]]<=deep[v]) break;
		ans=my_min(ans,wei[u][i]);
		u=faq[u][i];
	}
	while (u!=v)
	{
		for (i=0;(1<<i)<=n;++i)
			if (faq[u][i]==faq[v][i]) break;
		if (i>0) --i;
		ans=my_min(ans,wei[u][i]);
		ans=my_min(ans,wei[v][i]);
		u=faq[u][i];
		v=faq[v][i];
	}
	return ans;
}

void huida()
{
	int u,v;
	scanf("%d",&q);
	sb();
	while (q--)
	{
		scanf("%d%d",&u,&v);
		if (deep[u]<deep[v]) printf("%d\n",lca(u,v));
		else printf("%d\n",lca(v,u));
	}
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	for (i=0;i<m;++i) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	sort(e,e+m,cmp);
	for (i=1;i<=n;++i) fa[i]=i;
	for (i=0;i<m;++i)
	{
		if (get(e[i].x)!=get(e[i].y))
		{
			add_edge(i);
			fa[e[i].x]=fa[e[i].y];
		}
	}
	visit[0]=visit[1]=1;
	tot=0;
	fan[1]=-1;
	for (i=1;i<=n;++i) faw[i]=INF;
	dfs(1);
	huida();
	return 0;
}

