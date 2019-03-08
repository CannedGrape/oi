#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int maxn=10003,maxm=50003*5;
struct Tedge
{
	int x,y,z;
}e[maxm];
int n,m,Link[maxn],pre[maxm],t[maxm],v[maxm],f[16][maxn],g[16][maxn],lim=0,tot=0,fa[maxn],s[maxn],depth[maxn];
bool vis[maxn];

bool cmp(const Tedge &a,const Tedge &b)
{
	return a.z>b.z;
}

int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}

void bfs(int S)
{
	int front=0,rear=1;
	vis[S]=1,s[front]=S;depth[S]=1;
	while(front!=rear)
	{
		int p=s[front];
		for(int i=Link[p];i;i=pre[i])
			if(!vis[t[i]])
			{
				vis[t[i]]=1;f[0][t[i]]=p,g[0][t[i]]=v[i];
				s[rear++]=t[i]; depth[t[i]]=depth[p]+1;
			}
		front++;
	}
}

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=getfa(e[i].x),fy=getfa(e[i].y);
		if(fx==fy)continue;else fa[fx]=fy;
		int x=e[i].x,y=e[i].y,z=e[i].z;
		pre[++tot]=Link[x]; Link[x]=tot; t[tot]=y; v[tot]=z;
		pre[++tot]=Link[y]; Link[y]=tot; t[tot]=x; v[tot]=z;
	}
	memset(g,120,sizeof(g));
//	cerr<<sizeof(g)+sizeof(f)<<endl;///////////////////////////////////////////////////////////////////
	for(int i=1;i<=n;i++)
		if(!vis[i])bfs(i);
	lim=int(log2(double(n)));
	lim=max(lim,0);
	for(int i=1;i<=lim;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j]=f[i-1][f[i-1][j]];
			g[i][j]=min(g[i-1][j],g[i-1][f[i-1][j]]);
		}
}

int ask(int x,int y)
{
	int res=1000000000;
	if(depth[x]<depth[y])swap(x,y);
	for(int i=lim;i>=0;i--)
		if((depth[x]-depth[y])&(1<<i))res=min(res,g[i][x]),x=f[i][x];
	if(x==y)return res;
	for(int i=lim;i>=0;i--)
		if(f[i][x]!=f[i][y])
		{
			res=min(res,g[i][x]);
			res=min(res,g[i][y]);
			x=f[i][x],y=f[i][y];
		}
	res=min(res,g[0][x]);
	res=min(res,g[0][y]);
	return res;
}

void work()
{
	int Q;scanf("%d",&Q);
	while(Q--)
	{
		int x,y,fx,fy;
		scanf("%d%d",&x,&y);
		fx=getfa(x),fy=getfa(y);
		if(fx!=fy){puts("-1");continue;}
		printf("%d\n",ask(x,y));
	}
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	init();
	work();
	return 0;
}
