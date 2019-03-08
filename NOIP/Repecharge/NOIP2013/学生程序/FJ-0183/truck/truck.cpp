#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#define maxe 50010
#define maxn 10010
#define fmax(a,b) a>b?a:b
#define minv(a,b) a<b?a:b
using namespace std;
struct edge{
	int x,y,v;
}a[maxe];

int n,m,q,hash[maxn],next[maxe],v[maxe];
int dist[maxn];
int x,y,z;
queue <int> c;
bool vis[maxn];
int spfa(int s){
  vis[s]=true;c.push(s);
  for (int i=1;i<=n;i++)  {
  dist[i]=-1;vis[i]=false;}
  
  dist[s]=0;vis[s]=true;
  while (!c.empty()) {
	int now=c.front(),k=hash[now];c.pop();
	while (k!=0){int tmp;
		if (now==s) tmp=v[k];
		else  tmp=minv(dist[now],v[k]);
	    if (tmp>dist[a[k].y]) {
	    dist[a[k].y]=tmp;
	    if (!vis[a[k].y]) c.push(a[k].y);}
	    k=next[k];
	}
	vis[now]=false;
  }
  return dist[y];
}
int main(){
   freopen("truck.in","r",stdin);
   freopen("truck.out","w",stdout);
   scanf("%d%d",&n,&m);int p=0;
   for (int i=1;i<=m;i++) {
	   scanf("%d%d%d",&x,&y,&z);p++;
	   a[p].x=x;a[p].y=y;v[p]=z;
	   next[p]=hash[x];
	   hash[x]=p;
	   p++;
	   a[p].x=y;a[p].y=x;v[p]=z;
	   next[p]=hash[y];
	   hash[y]=p;
   }
   scanf("%d",&q);
   for (int i=1;i<=q;i++) {
		scanf("%d%d",&x,&y);
		printf("%d\n",spfa(x));
   } 
   fclose(stdin);
   fclose(stdout);
}
