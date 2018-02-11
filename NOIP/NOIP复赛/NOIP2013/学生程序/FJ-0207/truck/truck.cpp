#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,q;
int dist[51][50005];
int flag[51][50005];
int s[5000005],ls,le;
int r[10005];
struct ask
{   int f,t;
}b[10005];
struct edge
{	int f,t,w;
}a[1000005];
void spfa (int k,int T)
{   int i,j;
	while (ls<le && le<=T)
	{for (i=r[s[ls]];i<r[s[ls]+1];i++)
	 {if (min(dist[k][a[i].f],a[i].w)>dist[k][a[i].t])
	  {dist[k][a[i].t]=min(dist[k][a[i].f],a[i].w);
	   if (!flag[k][a[i].t])
	   {flag[k][a[i].t]=1;
	    s[le]=a[i].t;
	    le++;
	   }
	  }
	 }
	 flag[k][s[ls]]=0;
	 ls++;
	}
}
int cmp(const edge &x,const edge &y)
{   return x.f<y.f;
}
int main()
{	freopen ("truck.in","r",stdin);
	freopen ("truck.out","w",stdout);
	int i,j,maxx;
	scanf ("%d %d",&n,&m);
	for (i=1;i<=m;i++)
	{scanf ("%d %d %d",&a[i].f,&a[i].t,&a[i].w);
	 a[i+m].t=a[i].f,a[i+m].f=a[i].t,a[i+m].w=a[i].w;
	}
	sort(a+1,a+2*m+1,cmp);
	for (i=1;i<=2*m;i++)
	{if (a[i].f!=a[i-1].f)
	  r[a[i].f]=i;
	}
	r[n+1]=2*m+1;
	for (i=n;i>=1;i--)
	 if (r[i]==0)
	  r[i]=r[i+1];
	for (i=1;i<=min(40,n);i++)
	{for (j=1;j<=700000;j++)
	  s[j]=0;
	 for (j=1;j<=50000;j++)
	  if (i!=j)
	   dist[i][j]=-2147000005;
	  else
	   dist[i][j]=2147000005;
	 s[1]=i;
	 ls=1;
	 le=2;
	 spfa(i,5000000);
	}
	scanf ("%d",&q);
	for (i=1;i<=q;i++)
	{scanf ("%d %d",&b[i].f,&b[i].t);
	 for (j=1;j<=1000;j++)
	  s[j]=0;
	 for (j=1;j<=10000;j++)
	  if (b[i].f!=j)
	   dist[45][j]=-2147000005;
	  else
	   dist[45][j]=2147000005;
	 s[1]=b[i].f;
	 ls=1;
	 le=2;
	 spfa(45,1000);
	 maxx=dist[45][b[i].t];
	 for (j=r[b[i].f];j<r[b[i].f+1];j++)
	  if (a[j].t==b[i].t)
	   maxx=max(maxx,a[j].w);
	 for (j=1;j<=min(40,n);j++)
	  maxx=max(maxx,min(dist[j][b[i].f],dist[j][b[i].t]));
	 if (maxx<-2100000000)
	  printf ("-1\n");
	 else
	  printf ("%d\n",maxx);
	}
	return 0;
}
