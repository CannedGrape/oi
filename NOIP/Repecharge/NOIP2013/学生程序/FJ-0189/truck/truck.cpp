#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;
struct bian
{
	int from,to,w;
}a[100000];
int n,m,q,f[100000],t[100000],b[100000],w[100000],father[100000];
int cmp(const bian &a,const bian &b)
{
	if(a.w>b.w) return 1;
	else return 0;
}
struct ee
{
	int to,next,w;
}edge[100000];
int find(int x)
{
	if(father[x]==x) return x;
	else 
	{
	father[x]=find(father[x]);
	return father[x];
	}
}
int head[100000],e=0;
void insert(int x,int y,int w)
{
	e++;
	edge[e].to=y;
	edge[e].w=w;
	edge[e].next=head[x];
	head[x]=e;
}
int krusal()
{
	sort(a+1,a+m+1,cmp);
	int tail=0,fx,fy;
	for(int i=1;i<=m;i++)
	{
		fx=find(a[i].to);
		fy=find(a[i].from);
		if(fx!=fy) 
		{
			insert(a[i].from,a[i].to,a[i].w);
			insert(a[i].to,a[i].from,a[i].w);
			father[fx]=fy;
			tail++;
			if(tail==n-1) break;
		}
	}
	return 0;
}
int low(int a,int b)
{
	if(a>b) return b;
	else return a;
}
struct bbb
{
	int father,v;
}d[100000];
int find1(int x)
{
	int t=d[x].father;
	if(t==x) return x;
	else
	{
		d[x].father=find1(d[x].father);
		d[x].v=low(d[x].v,d[t].v);
		return d[x].father;
	}
}
int temp[100000];
int dfs(int n)
{
	int fx=0,fy=0;
	temp[n]=1;
	for(int i=head[n];i!=0;i=edge[i].next)
	if(!temp[edge[i].to])
	{
		dfs(edge[i].to);
        d[edge[i].to].father=d[n].father;
        d[edge[i].to].v=low(d[edge[i].to].v,edge[i].w);
	}
	for(int i=1;i<=q;i++)
	if(b[i]!=1)
	{
	fx=find1(f[i]);
	fy=find1(t[i]);
	if(fx==fy)
	 {
		b[i]=1;
		w[i]=low(d[f[i]].v,d[t[i]].v);
	 }
	}
	return 0;
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	 {
			scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].w);
	 }
	cin>>q;
	for(int i=1;i<=q;i++)
	 {
		scanf("%d%d",&f[i],&t[i]);
	 }
	for(int i=1;i<=n;i++)
	 father[i]=i;
	krusal();
	for(int i=1;i<=n;i++)
	 {
			d[i].father=i;
			d[i].v=INT_MAX;
	 }
	memset(b,0,sizeof(b));
	dfs(1);
	for(int i=1;i<=q;i++)
	 if(b[i]==1) cout<<w[i]<<endl;
	 else cout<<-1<<endl;
	return 0;
}
