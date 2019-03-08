#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
const int Maxn=10002,Maxm=50002,inf=999999999+208;
int n,m,q;
struct Edge{
	int u,v,w;
}E[Maxm];
bool cmp(Edge a,Edge b){return a.w>b.w;}
int get()
{
	int f=0,v=0;char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') f=1;else v=ch-48;
	while (isdigit(ch=getchar())) v=v*10+ch-48;
	if (f) return -v;else return v;
}
int fa[Maxn];
int getfa(int x){if (fa[x]==x) return x;fa[x]=getfa(fa[x]);return fa[x];}
int fst[Maxn],next[Maxm<<1],to[Maxm<<1],w[Maxm<<1],En=0;
void addedge(int u,int v,int W)
{
	next[++En]=fst[u];fst[u]=En;to[En]=v;w[En]=W;
	next[++En]=fst[v];fst[v]=En;to[En]=u;w[En]=W;
}
int dep[Maxn],f[Maxn][16],minn[Maxn][16];
int Q[Maxn];
void bfs(int root)
{
	dep[root]=1;Q[1]=root;
	int l=1,r=2;
	while (l<r)
	{
		int x=Q[l];
		for (int k=fst[x];k;k=next[k])
		{
			if (dep[to[k]]) continue;
			dep[to[k]]=dep[x]+1;
			f[to[k]][0]=x;minn[to[k]][0]=w[k];
			Q[r++]=to[k];
		}
		l++;
	}
}
int lca(int x,int y)
{
	int ans=inf;
	if (dep[x]>dep[y]) swap(x,y);
	int k=13;
	while (dep[x]<dep[y])
	{
		while (dep[f[y][k]]<dep[x]) k--;
		ans=min(ans,minn[y][k]);y=f[y][k];
	}
	if (x==y) return ans;
	k=13;
	while (f[x][0]!=f[y][0])
	{
		while (f[x][k]==f[y][k])k--;
		ans=min(ans,minn[x][k]);
		ans=min(ans,minn[y][k]);
		x=f[x][k];y=f[y][k];
	}
	ans=min(ans,minn[x][0]);
	ans=min(ans,minn[y][0]);
	return ans;
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	n=get();m=get();
	for (int i=1;i<=m;i++) E[i].u=get(),E[i].v=get(),E[i].w=get();
	sort(E+1,E+m+1,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int t1=getfa(E[i].u),t2=getfa(E[i].v);
		if (t1!=t2)
		{
			fa[t1]=t2;
			addedge(E[i].u,E[i].v,E[i].w);
		}
	}
	for (int i=1;i<=n;i++) if (!dep[i]) bfs(i);
	for (int k=1;k<=13;k++)
	{
		for (int i=1;i<=n;i++)
		{
			f[i][k]=f[f[i][k-1]][k-1];
			minn[i][k]=min(minn[i][k-1],minn[f[i][k-1]][k-1]);
		}
	}
	q=get();
	for (int i=1;i<=q;i++)
	{
		int x=get(),y=get();
		if (getfa(x)!=getfa(y)){printf("-1\n");continue;}
		printf("%d\n",lca(x,y));
	}
	return 0;
}
