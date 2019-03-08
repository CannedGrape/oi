#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define INF (2139062143)
#define For(i,n) for(int i=1;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Rep(i,n) for(int i=0;i<n;i++)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define For2k(i,k,n) for(int i=k;i<=n;i++)
#define For2kD(i,k,n) for(int i=n;i>=k;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define MAXN (10000+100)
#define MAXM (100000+100)
#define MAXQ (30000+100)
#define MAXZ (100000+100)
typedef long long ll;
int n,m,q;
struct Edge
{
   int x,y,z;
   friend bool operator<(Edge a,Edge b){return a.z>b.z;}    
}e[MAXM];
int father[MAXN];
int getfather(int x)
{
    if (father[x]==x) return x;
    else return father[x]=getfather(father[x]);
}
void union2(int x,int y)
{
    father[getfather(x)]=father[getfather(y)];
}
int edge[MAXM]={0},next[MAXM]={0},pre[MAXM]={0},weight[MAXM]={0},size=1;
void addedge(int u,int v,int w)
{
     edge[++size]=v;
     weight[size]=w;
     next[size]=pre[u];
     pre[u]=size;
}
void addedge2(int u,int v,int w){addedge(u,v,w),addedge(v,u,w);}
int f[MAXN][100]={{0}},dep[MAXN],w[MAXN][100]={{0}};
void dfs(int x,int fa,int d)
{
     dep[x]=d;
     f[x][0]=fa;
     Forp(x)
     {
        int v=edge[p];
        if (v^fa)
        {
           dfs(v,x,d+1);w[v][0]=weight[p];
        }    
     }
}
void dfs2(int x,int fa)
{
     int i=x;
     for(int j=1;;j++)
     {
          if (f[f[i][j-1]][j-1])
          {
             f[i][j]=f[f[i][j-1]][j-1];
             w[i][j]=min(w[i][j-1],w[f[i][j-1]][j-1]);
          }else break;
     }
    
     Forp(x)
     {
        int v=edge[p];
        if (v^fa)
        {
           dfs2(v,x);
        }    
     }
}

int bin[20];
int beizheng(int x,int y)
{
    if (x==y) return 0;
    int ans=MAXZ;
    if (dep[x]>dep[y]) swap(x,y);
    if (dep[x]<dep[y])
    {
       int p=dep[y]-dep[x];
       Rep(i,16) if (p&bin[i]) ans=min(ans,w[y][i]),y=f[y][i];
    } 
    int p=15;
    while (x!=y)
    {
          while (p>0&&f[x][p]==f[y][p]) p--;
          ans=min(ans,w[x][p]);x=f[x][p];
          ans=min(ans,w[y][p]),y=f[y][p];
    }
    return ans;
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    For(i,m) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    sort(e+1,e+1+m);
    
    For(i,n) father[i]=i;
    For(i,m)
    {
        if (getfather(e[i].x)!=getfather(e[i].y))
        {
            union2(e[i].x,e[i].y);
            addedge2(e[i].x,e[i].y,e[i].z);
        }
    }
    For(i,n) if (getfather(i)==i) dfs(i,0,1);
//  For(i,n) cout<<f[i][0]<<' '<<w[i][0]<<endl;
    
    For(i,n) if (getfather(i)==i) dfs2(i,0);
    /*
    For(i,n)
    {
       for(int j=1;;j++)
       {
          if (f[f[i][j-1]][j-1])
          {
             f[i][j]=f[f[i][j-1]][j-1];
             w[i][j]=min(w[i][j-1],w[f[i][j-1]][j-1]);
          }else break;
       }
    }*/
    
    bin[0]=1;
    For(i,15) bin[i]=bin[i-1]<<1;
    
    scanf("%d",&q);
    For(i,q)
    {
       int x,y;
       scanf("%d%d",&x,&y);
       if (getfather(x)!=getfather(y)) puts("-1");
       else
       {
           printf("%d\n",beizheng(x,y));
       } 
    }
    
//  while(1);
    return 0;
}
