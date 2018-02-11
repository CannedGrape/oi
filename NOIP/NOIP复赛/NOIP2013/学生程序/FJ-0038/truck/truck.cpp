#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct edge
{
       int u,v,l;
}e[50500];
const int power2[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int n,m,q,root[10100]={},f[20100][21]={},k[20100][21]={},d[20100]={};
int last[10100]={},next[110000]={},end[110000]={},l[110000]={},total_edge=0;
bool checked[10100]={};
bool cmp(edge e1,edge e2);
void init();
int get_root(int r);
inline void add_edge(int &u,int &v,int &l_)
{
       next[++total_edge]=last[u];
       last[u]=total_edge;
       end[total_edge]=v;
       l[total_edge]=l_;
}
void kruskal()
{
     for(int i=1;i<=m;++i)
     {
             int u_root=get_root(e[i].u);
             int v_root=get_root(e[i].v);
             if(u_root != v_root)
             {
                       root[u_root]=v_root;
                       add_edge(e[i].u,e[i].v,e[i].l);
                       add_edge(e[i].v,e[i].u,e[i].l);
             }
     }
}
void bfs(int start)
{
     queue<int>q;
     q.push(start);
     checked[start]=true;
     while(!q.empty())
     {
         int s=q.front();
         q.pop();
         for(int i=last[s];i;i=next[i])
         {  
             int j=end[i];
             if(!checked[j])
             {
                 q.push(j);
                 checked[j]=true;
                 f[j][0]=s;
                 k[j][0]=l[i];
                 d[j]=d[s]+1;
             }
         }
     }
}
void rmq()
{
     for(int j=1;power2[j]<=n;++j)
         for(int i=1;i<=n;++i)
         {
             f[i][j]=f[f[i][j-1]][j-1];
             k[i][j]=min(k[i][j-1],k[f[i][j-1]][j-1]);
         }
}
void deal()
{
     scanf("%d",&q);
     for(int i=1;i<=q;++i)
     {
         int u,v,ans=0x3fffffff;
         scanf("%d%d",&u,&v);
         int u_root=get_root(u);
         int v_root=get_root(v);
         if(u_root != v_root)
             printf("%d\n",-1);
         else
         {
             if(d[u]>d[v])
             {
                 int tmp=u;
                 u=v;
                 v=tmp;
             }
             while(d[u]!=d[v])
             {
                 int t=0;
                 while(power2[t]<=d[v]-d[u])
                     ++t;
                 ans=min(ans,k[v][t-1]);
                 v=f[v][t-1];
             }
             if(u==v)
             {
                 printf("%d\n",ans);
                 continue;
             }
             while(f[u][0]!=f[v][0])
             {
                 int t=0;
                 while(f[u][t]!=f[v][t])
                     ++t;
                 ans=min(ans,k[u][t-1]);
                 ans=min(ans,k[v][t-1]);
                 u=f[u][t-1];
                 v=f[v][t-1];
             }
             ans=min(ans,k[u][0]);
             ans=min(ans,k[v][0]);
             printf("%d\n",ans);
         }
     }
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    init();
    kruskal();
    for(int i=1;i<=n;++i)
        if(get_root(i)==i)
            bfs(i);
    rmq();
    deal();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

bool cmp(edge e1,edge e2)
{
     return e1.l>e2.l;
}
void init()
{
     scanf("%d%d",&n,&m);
     for(int i=1;i<=m;++i)
             scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
     for(int i=1;i<=n;++i)
             root[i]=i;
     sort(e+1,e+m+1,cmp);
     for(int i=0;i<=n;++i)
         for(int j=0;j<=20;++j)
             k[i][j]=0x3fffffff;
}
int get_root(int r)
{
    if(r!=root[r])
        root[r]=get_root(root[r]);
    return root[r];
}
