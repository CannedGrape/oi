#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct road{int u,v,q;};
int f[10001];
int n,m,q;
road r[50001];
road t[10001];
int dis[10001][10001];
bool cmp(road w,road e)
{if(w.q>e.q) return true;
  return false;
}
int fa(int far)
{if(f[far]==far) return far;
  return f[far]=fa(f[far]);
}
int main()
{freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
	 {scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].q);}
  sort(r+1,r+m+1,cmp);
  for(int i=1;i<=n;i++)
     {f[i]=i;}
  int p=0;
  for(int i=1;i<=m;i++)
    {if(fa(r[i].u)!=fa(r[i].v))
		{f[fa(r[i].v)]=fa(r[i].u);
		  p++;
		  t[p].u=r[i].u;t[p].v=r[i].v;t[p].q=r[i].q;
		}
	 }
  for(int i=1;i<=p;i++)
    {for(int j=1;j<=n;j++)
	    if((dis[t[i].u][j]>t[p].q||dis[t[i].u][j]==0)&&fa(j)==fa(t[i].u))
		  {dis[t[i].u][j]=t[p].q;
			dis[j][t[i].u]=t[p].q;}
	  for(int j=1;j<=n;j++)
	    if((dis[t[i].v][j]>t[p].q||dis[t[i].v][j]==0)&&fa(j)==fa(t[i].v))
		  {dis[t[i].v][j]=t[p].q;
			dis[j][t[i].v]=t[p].q;}
	}
   scanf("%d",&q);
   for(int i=1;i<=q;i++)
     {int g,h;
	   scanf("%d%d",&g,&h);
	   if(fa(g)!=fa(h))printf("-1\n");
	   else printf("%d\n",dis[g][h]);
	 }
  return 0;
}
