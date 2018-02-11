#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10005,maxm=50005,maxq=1000000;
int tot,w[maxm*2],e[maxm*2],first[maxn],next[maxm*2];
int n,m,q[maxq+10],dis[maxn];
bool vis[maxn];
int get()
{
	int res=0,v=0;char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') v=1;else res=ch-48;
	while (isdigit(ch=getchar())) res=res*10+ch-48;
	if (v) return -res;return res;
}
void add(int x,int y,int z)
{
  w[++tot]=y;next[tot]=first[x];e[tot]=z;first[x]=tot;
  w[++tot]=x;next[tot]=first[y];e[tot]=z;first[y]=tot;
}
void bfs(int S,int T)
{
  int l=1,r=2;
  for (int i=1;i<=n;i++) dis[i]=0,vis[i]=0;
  vis[S]=1,dis[S]=10000000;q[1]=S;
  while (l!=r)
  {
	int x=q[l];
	if (dis[x]<dis[T]) vis[x]=0,l=l%maxq+1;
	for (int i=first[x];i;i=next[i])
	{
	  if (dis[w[i]]<min(dis[x],e[i]))
	  {
		dis[w[i]]=min(dis[x],e[i]);
		if (!vis[w[i]]) vis[w[i]]=1,q[r]=w[i],r=r%maxq+1; 
	  }
	}
	vis[x]=0,l=l%maxq+1;
  }
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	n=get(),m=get();
	int x,y,z,Q;
	for (int i=1;i<=m;i++) x=get(),y=get(),z=get(),add(x,y,z);
	Q=get();
	while (Q--)
	{
	  x=get(),y=get();
	  if (x<1||x>n||y<1||y>n) {printf("-1\n");continue;}
	  bfs(x,y);
	  if (dis[y]==0) printf("-1\n");
	  else printf("%d\n",dis[y]);
	}
	return 0;
}

