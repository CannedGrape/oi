#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=10005;
const int maxm=50005;
const int inf=10000005;
struct dot{int s,e,c,loc,next;bool vis;}map[2*maxm],rmq[maxn][21];
int Link[maxn],fa[maxn],step[maxn],n,m,Q,ans,tot,Dep;
bool vis[maxn];
void ins(int a,int b,int c)
{
	map[tot].s=a,map[tot].e=b,map[tot].c=c,map[tot].loc=tot;
	map[tot].next=Link[a],Link[a]=tot,tot++;
}
bool cmp(const dot &x,const dot &y)
{
	return x.c>y.c;
}
bool cmp2(const dot &x,const dot &y)
{
	return x.loc<y.loc;
}
int getfa(int x)
{
	if (x==fa[x]) return x;
	int tmp=getfa(fa[x]); fa[x]=tmp; return tmp;
}
void kruskal()
{
	sort(map+1,map+tot,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<tot;i++)
	{
		int u=map[i].s,v=map[i].e,fu,fv;
		fu=getfa(u),fv=getfa(v);
		if (fu!=fv) fa[fu]=fv,map[i].vis=1;
	}
	sort(map+1,map+tot,cmp2);
	for (int i=1;i<=tot;i++) if (map[i].vis) map[((i-1)^1)+1].vis=1;
}
void dfs(int x,int Pre,int cost)
{
	rmq[x][0].loc=Pre,rmq[x][0].c=cost,step[x]=step[Pre]+1,Dep=max(Dep,step[x]),vis[x]=1;
	for (int p=Link[x];p;p=map[p].next)
	{
		if (!map[p].vis) continue; int y=map[p].e;
		if (y!=Pre) dfs(y,x,map[p].c);
	}
}
void rmqinit()
{
	double t=log(Dep)/log(2); Dep=(int)t+1;
	for (int j=1;j<=Dep;j++)
		for (int i=1;i<=n;i++)
		{
			rmq[i][j].c=min(rmq[i][j-1].c,rmq[rmq[i][j-1].loc][j-1].c);
			rmq[i][j].loc=rmq[rmq[i][j-1].loc][j-1].loc;
		}
}
void init()
{
	scanf("%d%d",&n,&m); tot=1; int a,b,c;
	for (int i=1;i<=m;i++) scanf("%d%d%d",&a,&b,&c),ins(a,b,c),ins(b,a,c);
	kruskal(); memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
		if (!vis[i]) step[i]=1,dfs(i,0,0);
	rmqinit();
}
void work()
{
	scanf("%d",&Q); int x,y;
	for (int i=1;i<=Q;i++)
	{
		scanf("%d%d",&x,&y);
		if (x==10000 && y==1)
		{
			int tmp;
			tmp++;
		}
		if (getfa(x)!=getfa(y)) {printf("-1\n"); continue;}
		int ans=inf;
		if (step[x]<step[y]) swap(x,y);
		for (int j=Dep;j>=0 && step[x]>step[y];j--)
		{
			int tx=rmq[x][j].loc;
			if (step[tx]>=step[y]) ans=min(ans,rmq[x][j].c),x=tx;
		}
		for (int j=Dep;j>=0;j--)
		{
			int tx=rmq[x][j].loc,ty=rmq[y][j].loc;
			if (tx!=ty) ans=min(ans,min(rmq[x][j].c,rmq[y][j].loc)),x=tx,y=ty;
		}
		if (x!=y) ans=min(ans,min(rmq[x][0].c,rmq[y][0].c));
		printf("%d\n",ans);
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

