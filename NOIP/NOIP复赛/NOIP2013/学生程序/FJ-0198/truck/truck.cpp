#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<queue>

using namespace std;

const int Maxn=10010;
const int Maxm=50010;
const int inf=9999999+413;

int n,m,q,tot=0,maxd;
int fa[Maxn],fst[Maxn],to[2*Maxn],pre[2*Maxn],l[2*Maxn];
int len[Maxn][100],rmq[Maxn][100];
int d[Maxn];

struct Road
{
	int x,y,z;
}r[Maxm];

void add(int x,int y,int c)
{
	to[++tot]=y; l[tot]=c; pre[tot]=fst[x]; fst[x]=tot;
	to[++tot]=x; l[tot]=c; pre[tot]=fst[y]; fst[y]=tot;
}

int getfa(int idx)
{
	if(fa[idx]!=idx) fa[idx]=getfa(fa[idx]);
	return fa[idx];
}

bool cmp(Road x,Road y){return x.z>y.z;}

void Kruskal_Max()
{
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(tot>=2*(n-1)) break;
		int x=getfa(r[i].x),y=getfa(r[i].y);
		if(x!=y)
		{
			fa[x]=y; 
			add(r[i].x,r[i].y,r[i].z);
		}
	}
}

void dfs(int x,int y,int k)
{
	rmq[x][k]=y;
	for(int t=fst[x];t;t=pre[t])
	{
		if(d[to[t]]) continue;
		d[to[t]]=d[x]+1; len[to[t]][k]=l[t];
		dfs(to[t],x,k);
	}
}

int lca(int x,int y)
{
	int tans=inf;
	
	if(d[x]<d[y]) swap(x,y);
	for(int i=maxd;i>=0;i--)
	{
		if(d[rmq[x][i]]>=d[y]) 
			tans=min(tans,len[x][i]),x=rmq[x][i];
	}
	if(x==y) return tans;
	for(int i=maxd;i>=0;i--)
	{
		if(rmq[x][i]!=rmq[y][i])
		{
			tans=min(tans,min(len[x][i],len[y][i]));
			x=rmq[x][i]; y=rmq[y][i];
		}
	}
	tans=min(tans,min(len[x][0],len[y][0]));
	return tans;
}

void work()
{
	Kruskal_Max();
	
	maxd=(int)(log2(n));
	for(int i=1;i<=n;i++) d[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=maxd;j++) len[i][j]=inf;
	d[1]=1; rmq[1][0]=0; len[1][0]=100010;
	dfs(1,0,0);
	
	for(int i=2;i<=n;i++)
	{
		int mi=0,t=1;
		for(int j=1;j<=maxd;j++)
		{
			mi++;
			if(d[i]-t<0) break;
			rmq[i][mi]=rmq[rmq[i][mi-1]][mi-1];
			len[i][mi]=min(len[i][mi-1],len[rmq[i][mi-1]][mi-1]);
			t*=2;
		}
	}
	
	//for(int i=1;i<=n;i++) printf("%d ",rmq[i][0]);
	//printf("%d %d",len[2][1],len[3][1]);
	scanf(" %d",&q);
	int a,b;
	for(int i=1;i<=q;i++)
	{
		scanf(" %d %d",&a,&b);
		
		if(fa[a]!=fa[b])
		{printf("-1\n"); continue;}
		
		int ans=lca(a,b);
		printf("%d\n",ans);
	}
}

void init()
{
	scanf(" %d %d",&n,&m);
	for(int i=1;i<=m;i++) scanf(" %d %d %d",&r[i].x,&r[i].y,&r[i].z);
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	
	init();
	work();
	
	//system("pause");
	return 0;
}

