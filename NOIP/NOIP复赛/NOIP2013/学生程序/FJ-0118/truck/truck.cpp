#include<cstdio>
#include<cstring>
using namespace std;
const int MAXM=50010;
const int MAXZ=100000;
int e[2*MAXM][4];
int p[10010];
int dis[10010][10010];
int que[999999];
bool vis[10010];
int head,tail;
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
void add(int u,int v,int w,int i)
{
    e[i][0]=u;
    e[i][1]=v;
    e[i][2]=w;
    e[i][3]=p[u];
    p[u]=i;
    return;     
}
void spfa(int sx)
{
    int u,v;
    head=0,tail=1;
    memset(vis,0,sizeof(vis));
    que[1]=sx;
    vis[sx]=1;
    while(head<tail)
    {
       head++;
       u=que[head];
       int ed=p[u];
       while(ed)
       {
          v=e[ed][1];
          int mz=min(e[ed][2],dis[sx][u]);
          if(dis[sx][v]<mz)
          {
             dis[sx][v]=mz;
             dis[v][sx]=mz;
             if(!vis[v])
             {
               tail++;
               que[tail]=v;
               vis[v]=1;           
             }                        
          }
          ed=e[ed][3];
       }
       vis[u]=0;                
    } 
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int n,m,i,u,v,w;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
       scanf("%d%d%d",&u,&v,&w);
       add(u,v,w,i);
       add(v,u,w,i+m);     
    }
    for(i=1;i<=n;i++) dis[i][i]=99999;
    for(i=1;i<=n;i++)
    { 
       spfa(i); 
    }
    int q;
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
       scanf("%d%d",&u,&v);
       if(dis[u][v])
       {
          printf("%d\n",dis[u][v]);              
       }
       else
       {
          printf("-1\n");    
       }
    }
    return 0;
}
