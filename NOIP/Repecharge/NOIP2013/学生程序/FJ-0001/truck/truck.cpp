#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q,flag[100],done[100];
struct ask{int s,t,ans,num;}w[30010],big[30010],small[30010];
struct edge{int u,v,len;}p[50010];
int fa[100][10010];
int find(int step,int now)
{
	if(fa[step][now]==now)
		return now;
	return fa[step][now]=find(step,fa[step][now]);
}
void solve(int step,int whead,int wtail,int low,int high)
{
	int i;
	if(flag[step]==0)
	{
		flag[step]=1;
		for(i=1;i<=n;++i)
			fa[step][i]=i;
	}
	
	if(low==high)
	{
		for(i=whead;i<=wtail;++i)
			w[i].ans=p[low].len;
		return;
	}
	
	int mid=(low+high)>>1;
	for(i=done[step]+1;i<=mid;++i)
		fa[step][find(step,p[i].u)]=find(step,p[i].v);
	done[step]=mid;
	
	int bigtop=0,smalltop=0;
	for(i=whead;i<=wtail;++i)
		if(find(step,w[i].s)==find(step,w[i].t))
			big[++bigtop]=w[i];
		else
			small[++smalltop]=w[i];
	
	int d=whead,k;
	for(i=1;i<=bigtop;++i)
	{
		w[d]=big[i];
		++d;
	}
	k=d-1;
	for(i=1;i<=smalltop;++i)
	{
		w[d]=small[i];
		++d;
	}
	solve(step+1,whead,k,low,mid);
	solve(step+1,k+1,wtail,mid+1,high);
}
bool cmplen(edge a,edge b)
{
	return a.len>b.len;
}
bool cmpnum(ask a,ask b)
{
	return a.num<b.num;
}
int main()
{
	int i;
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
		scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].len);
	scanf("%d",&q);
	sort(p+1,p+m+1,cmplen);
	for(i=1;i<=q;++i)
	{
		scanf("%d%d",&w[i].s,&w[i].t);
		w[i].num=i;
	}
	solve(0,1,q,1,m);
	for(i=done[0]+1;i<=m;++i)
		fa[0][find(0,p[i].u)]=find(0,p[i].v);
	sort(w+1,w+q+1,cmpnum);
	for(i=1;i<=q;++i)
		if(find(0,w[i].s)==find(0,w[i].t))
			printf("%d\n",w[i].ans);
		else
			printf("-1\n");
	return 0;
}
