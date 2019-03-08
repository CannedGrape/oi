#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=10100;
const int maxm=50500;
const int maxq=30300;
const int inf=1000000000;

int n,m,L,tot,que,step;
int E[2*maxm],w[2*maxm],pre[2*maxm],fst[maxn];
int l1[maxn],l2[maxn],l3[maxn],r1[maxn],r2[maxn],r3[maxn];
int f[maxn][20],g[maxn][20],dep[maxn],num[maxn],vis[maxn],ft[maxn],cnt[maxn];
int dist[2020][2020];

struct Edge
{
       int a,b,c;
       Edge(){};
       Edge(int x,int y,int z) {a=x; b=y; c=z;}
       bool operator <(const Edge &rhs)const
       {
            return vis[a]<vis[rhs.a];
       }
}e[maxm];

struct Query
{
       int x,y;
       bool operator <(const Query &rhs)const
       {
            return vis[x]<vis[rhs.x];
       }
}Q[maxq];


struct Heap
{
       int x,y;
       Heap(){};
       Heap(int a,int b) {x=a; y=b;}
       bool operator <(const Heap &rhs)const //Big Heap************* 
       {
            return y<rhs.y;
       }
};

priority_queue<Heap> H;

void add(int a,int b,int c)
{
     E[++L]=b; w[L]=c; pre[L]=fst[a]; fst[a]=L;
}

void init()
{
     L=tot=0; int a,b,c;
     memset(fst,0,sizeof(fst));
     scanf("%d %d",&n,&m);
     for(int i=1;i<=m;i++)
     {
         scanf("%d %d %d",&a,&b,&c);
         add(a,b,c); add(b,a,c);
         e[i]=Edge(a,b,c);
     }
}

void Dijkstra(int S)
{
     for(int i=0;i<=n;i++) dist[S][i]=-1,vis[i]=0;
     while(!H.empty()) H.pop();
     H.push(Heap(S,dist[S][S]=inf));
     while(!H.empty())
     {
           int u=H.top().x; H.pop();
           if(vis[u]) continue; vis[u]=1;
           for(int k=fst[u];k;k=pre[k])
               if(!vis[E[k]] && min(dist[S][u],w[k])>dist[S][E[k]])
                  H.push(Heap(E[k],dist[S][E[k]]=min(dist[S][u],w[k])));
     }
}

void work1()
{
     int Q,x,y;
     for(int i=1;i<=n;i++) Dijkstra(i);
     scanf("%d",&Q);
     for(int i=1;i<=Q;i++)
     {
         scanf("%d %d",&x,&y);
         printf("%d\n",dist[x][y]);
     }
}

void dfs1(int x,int z)
{
     vis[x]=z; cnt[z]++;
     for(int k=fst[x];k;k=pre[k]) if(!vis[E[k]]) dfs1(E[k],z);
}

void dfs2(int x,int y)
{
     dep[x]=dep[y]+1;
     for(int k=fst[x];k;k=pre[k])
         if(E[k]!=y) f[E[k]][0]=x,g[E[k]][0]=w[k],dfs2(E[k],x);
}

bool cmp1(int a,int b)
{
     return vis[a]<vis[b];
}

bool cmp2(Edge A,Edge B)//**********
{
     return A.c>B.c;
}

void predeal()
{
     memset(vis,0,sizeof(vis));
     for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i,++tot);
     
     sort(e+1,e+m+1);
     for(int i=1;i<m;i++)
         if(vis[e[i].a]!=vis[e[i+1].a]) r1[vis[e[i].a]]=i,l1[vis[e[i+1].a]]=i+1;
     l1[vis[e[1].a]]=1; r1[vis[e[m].b]]=m;
     
     sort(Q+1,Q+que+1);
     for(int i=1;i<que;i++)
         if(vis[Q[i].x]!=vis[Q[i+1].x]) r2[vis[Q[i].x]]=i,l2[vis[Q[i+1].x]]=i+1;
     l2[vis[Q[1].x]]=1; r2[vis[Q[que].x]]=que;
     
     for(int i=1;i<=n;i++) num[i]=i;
     sort(num+1,num+n+1,cmp1);
     for(int i=1;i<n;i++)
         if(vis[num[i]]!=vis[num[i+1]]) r3[vis[num[i]]]=i,l3[vis[num[i+1]]]=i+1;
     l3[vis[num[1]]]=1; r3[vis[num[n]]]=n;
}

int find(int x)
{
    if(ft[x]!=x) ft[x]=find(ft[x]); return ft[x];
}

void Kruskal(int l,int r)
{
     sort(e+l,e+r+1,cmp2);//*****
     for(int i=l;i<=r;i++)
     {
         int x=find(e[i].a),y=find(e[i].b);
         if(x!=y) ft[x]=y,add(e[i].a,e[i].b,e[i].c),add(e[i].b,e[i].a,e[i].c);
     }
}

int lca(int a,int b)
{
    int Tas=inf;
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=step;i>=0;i--)
        if(dep[f[a][i]]>=dep[b]) Tas=min(Tas,g[a][i]),a=f[a][i];
    if(a==b) return Tas;
    for(int i=step;i>=0;i--)
        if(f[a][i]!=f[b][i]) Tas=min(Tas,min(g[a][i],g[b][i])),a=f[a][i],b=f[b][i];
    return min(Tas,min(g[a][0],g[b][0]));
}

void work2()
{
     scanf("%d",&que);
     for(int i=1;i<=que;i++) scanf("%d %d",&Q[i].x,&Q[i].y);
     predeal();
     for(int i=1;i<=tot;i++)//********
     {
         if(!l1[i] || !r1[i]) continue;
         L=0;
         for(int j=l3[i];j<=r3[i];j++) ft[num[j]]=num[j],fst[num[j]]=0;
         Kruskal(l1[i],r2[i]);//**************
         dfs2(num[l3[i]],0);
         step=int(log2(cnt[i]))+1;
         for(int j=1;j<=step;j++)
             for(int k=l3[i];k<=r3[i];k++)
                 f[num[k]][j]=f[f[num[k]][j-1]][j-1],g[num[k]][j]=min(g[num[k]][j-1],g[g[num[k]][j-1]][j-1]);
         for(int j=l2[i];j<=r2[i];j++)
         {
             if(vis[Q[j].x]!=vis[Q[j].y]) {printf("-1\n"); continue;}
             printf("%d\n",lca(Q[j].x,Q[j].y));
         }
     }
}

int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    init();
    if(n<=2000) work1(); else work2();
    return 0;
}


