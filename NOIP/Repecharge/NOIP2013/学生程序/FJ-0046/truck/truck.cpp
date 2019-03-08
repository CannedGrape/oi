#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
#define MXN 10010
#define MXM 100010
#define MXQ 30010
struct elist
{
       int u,v,w,last,tt;
}e[MXM],e2[MXM],e3[MXM];
int n,m,etot,Q,ans,dist[MXN],father[MXN],zh2[MXN],etot2,zh3[MXN],etot3;
int final[MXQ],xx[MXN],nn;
bool flag[MXN];
void eadd(int u,int v,int w){
     e[++etot].u=u;e[etot].v=v;e[etot].w=w;
}
void eadd2(int u,int v,int w)
{
     e2[++etot2].v=v;e2[etot2].w=w;e2[etot2].last=zh2[u];zh2[u]=etot2;
     e2[++etot2].v=u;e2[etot2].w=w;e2[etot2].last=zh2[v];zh2[v]=etot2;
}
void eadd3(int u,int v,int t)
{
     e3[++etot3].v=v;e3[etot3].tt=t;e3[etot3].last=zh3[u];zh3[u]=etot3;
     e3[++etot3].v=u;e3[etot3].tt=t;e3[etot3].last=zh3[v];zh3[v]=etot3;
}
void Init()
{
     int u,v,w;
     scanf("%d%d",&n,&m);
     for(int i=1;i<=m;i++)
       {
         scanf("%d%d%d",&u,&v,&w);
         eadd(u,v,w);
       }
}
bool cmp(elist a,elist b){return a.w>b.w;}
int getfather(int x){return ( father[x]==x?x:(father[x]=getfather(father[x])) );}
void kruskal()
{
     sort(e+1,e+etot+1,cmp);
     for(int i=1;i<=n;i++) father[i]=i;
     for(int i=1;i<=etot;i++)
       {
         int fu=getfather(e[i].u),fv=getfather(e[i].v);
         if(fu!=fv) {eadd2(e[i].u,e[i].v,e[i].w);father[fu]=fv;}
       }
}
void dfs(int p,int x)
{
     xx[x]=nn;flag[x]=1;
     for(int i=zh2[x];i;i=e2[i].last)
      if(e2[i].v!=p)
       {
         dist[e2[i].v]=min(dist[x],e2[i].w);
         dfs(x,e2[i].v);
       }
     for(int i=zh3[x];i;i=e3[i].last)
      if(xx[e3[i].v]==nn)
       {
         final[e3[i].tt]=min(dist[e3[i].v],dist[x]);
       }
}
void solve()
{
     int x,y;
     kruskal();
     scanf("%d",&Q);
     for(int i=1;i<=Q;i++)
       {
         scanf("%d%d",&x,&y);
         eadd3(x,y,i);
       }
     for(int i=1;i<=Q;i++) final[i]=-1;
     memset(dist,127,sizeof(dist));
     for(int i=1;i<=n;i++) if(!flag[i]) {nn++;dfs(0,i);}
     for(int i=1;i<=Q;i++) printf("%d\n",final[i]);
}
int main()
{
    freopen("truck.in","r",stdin);freopen("truck.out","w",stdout);
    Init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
