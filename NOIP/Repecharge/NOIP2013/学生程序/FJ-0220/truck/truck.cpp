#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int fi[50000],ne[200000],i,j,k,l,m,n,a[200000],b[200000],c[200000];
int h,t,q[50000],vis[20000],d[20000],pr[50000];
int ask;
struct node
{
	int x,y,p;
	bool operator < (const node &no) const
	{
		return (x<no.x);
	}
}u[50000];
void spfa(int start)
{
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[start]=100000000;q[1]=start;h=0;t=1;vis[start]=1;
	while (h!=t)
	{
		h++;if (h>n) h=1;
		k=q[h];j=fi[k];vis[k]=0;
		while (j!=0)
		{
			if  (d[b[j]]<min(d[a[j]],c[j]))
			{
				d[b[j]]=min(d[a[j]],c[j]);
				if  (vis[b[j]]==0)
				{
					t++;if (t>n) t=1;
					q[t]=b[j];vis[b[j]]=1;
				}
			}
			j=ne[j];
		}
	}
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		a[i+m]=b[i];b[i+m]=a[i];c[i+m]=c[i];
		if (fi[a[i]]==0) fi[a[i]]=i;
		   else {ne[i]=fi[a[i]];fi[a[i]]=i;}
		if (fi[a[i+m]]==0) fi[a[i+m]]=i+m;
		   else {ne[i+m]=fi[a[i+m]];fi[a[i+m]]=i+m;}
	}
	cin>>ask;
	for (i=1;i<=ask;i++)
	{
		cin>>u[i].x>>u[i].y;u[i].p=i;
		if (u[i].x>u[i].y){k=u[i].x;u[i].x=u[i].y;u[i].y=k;}
	}
	sort(u+1,u+1+ask);
	i=1;
	while (i<=ask)
	{
		spfa(u[i].x);j=i;
		while ((u[j].x==u[i].x)&&(j<=ask))
		{
			pr[u[j].p]=d[u[j].y];
			j++;
		}
		i=j;
	}
	for (i=1;i<=ask;i++) if (pr[i]==0) cout<<-1<<endl;else cout<<pr[i]<<endl;
	return 0;
}
