#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?(-(a)):(a))
#define MAX 2139062143
#define N 10004
#define M 50004
#define QU 30004
using namespace std;
int n,m,S,lll,head,tail,s,t,q,l,r,mid;
int last[N],qq[N],ans[QU],fa[N];
bool mark[N];
struct in
{
	int xx,yy,numq;
}Q[QU];
struct xxx
{
	int next,q,e;
}a[M<<1];
void add(int x,int y,int z)
{
	a[++lll].next=last[x];
	a[lll].e=y;
	a[lll].q=z;
	last[x]=lll;
}
int zhao(int aa)
{
	if(fa[aa]==0 ||fa[aa]==aa)return aa;
	return fa[aa]=zhao(fa[aa]);
}
bool cmp(in aa,in bb)
{
	if(aa.xx!=bb.xx)return aa.xx<bb.xx;
	return aa.yy<bb.yy;
}
int spfa(in aa,int dis)
{
	int i,now,v;
	memset(mark,0,sizeof(mark));
	s=aa.xx;t=aa.yy;
	qq[1]=t;head=0;tail=1;mark[t]=1;
	while(head<tail)
	{
		now=qq[++head];
		if(now==s)break;
		for(i=last[now];i;i=a[i].next)
		{
			v=a[i].e;
			if(a[i].q>=dis)
			{
				if(!mark[v])
				{
					mark[v]=1;
					qq[++tail]=v;
				}
			}
		}
	}
	if(mark[s])return 1;
	return 0;
}
int work(in aa)
{
	l=0;r=S;
	fa[aa.xx]=zhao(aa.xx);
	fa[aa.yy]=zhao(aa.yy);
	if(fa[aa.xx]!=fa[aa.yy])return -1;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(spfa(aa,mid))l=mid;
		else r=mid-1;
	}
	return l;
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int i,j,x,y,z,fx,fy;
	scanf("%d%d",&n,&m);
	lll=1;
	memset(last,0,sizeof(last));
	memset(fa,0,sizeof(fa));
	memset(ans,0,sizeof(ans));
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		S=max(S,z);
		add(x,y,z);add(y,x,z);
		fx=zhao(x);fy=zhao(y);
		if(fx!=fy)
			fa[y]=fx;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&Q[i].xx,&Q[i].yy);
		Q[i].numq=i;
	}
	sort(Q+1,Q+1+q,cmp);
	for(i=1;i<=q;i++)
	{
		if(Q[i].xx==Q[i-1].xx && Q[i].yy==Q[i-1].yy)
		{
			ans[Q[i].numq]=ans[Q[i-1].numq];
			continue;
		}
		ans[Q[i].numq]=work(Q[i]);
	}
	for(i=1;i<=q;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
