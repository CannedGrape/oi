#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAXM 50001
#define MAXQ 30001
#define MAXN 10001
#define maxint ((1<<30)-1)
#define minint (-maxint)
struct Edge{
       int next,weight,end,start;
}edge[MAXM*2],query[MAXQ];
struct T{
       int start,end,weight;
}e[MAXM];
int n,m,q,tot=0,cnt=0,last[MAXN]={},fa[MAXN],ans;
int tot2=0,last2[MAXN]={};
//bool intree[MAXN]={},vis[MAXN]={},road[MAXN]={};
inline void add_edge(int a,int b,int c)
{
       ++tot;
       edge[tot].next=last[a];
       edge[tot].end=b;
       edge[tot].weight=c;
       last[a]=tot;
}
inline void add(int a,int b,int c)
{
       ++cnt;
       e[cnt].start=a;
       e[cnt].end=b;
       e[cnt].weight=c;
}
inline void qadd(int a,int b)
{
       ++tot2;
       query[tot2].start=a;
       query[tot2].next=last2[a];
       query[tot2].end=b;
       query[tot2].weight=-1;
       last2[a]=tot;
}
inline bool cmp(T a,T b)
{
       return a.weight>b.weight;
}
inline void init()
{
       scanf("%d%d",&n,&m);
       register int i,a,b,c;
       for(i=1;i<=n;i++)
         fa[i]=i;
       for(i=1;i<=m;i++){
           scanf("%d%d%d",&a,&b,&c);
           add(a,b,c);
       }
       sort(e+1,e+m+1,cmp);
       scanf("%d",&q);
       for(i=1;i<=q;i++){
           scanf("%d%d",&a,&b);
           qadd(a,b);
       }
}
int find(int x)
{
    return (fa[x]==x?x:fa[x]=find(fa[x]));
}
inline void Kruskal()
{
       register int i,res=0;
       for(i=1;i<=m;i++){
           int u=find(e[i].start),v=find(e[i].end);
           if(u!=v){
               fa[u]=v;
               add_edge(e[i].start,e[i].end,e[i].weight);
               add_edge(e[i].end,e[i].start,e[i].weight);
               ++res;
           }
           if(res==n-1)
             break;
       }
}
/*void dfs(int x,int minw)
{
     register int i;
     w[x]=minw;
     intree[x]=vis[x]=road[x]=true;
     for(i=last[x];i;i=edge[i].next)
       if(edge[i].end!=father)
         dfs(edge[i].end,x,min(edge[i].weight,minw));
     road[x]=false;
     for(i=last2[x];i;i=query[i].next){
         if(road[)
       if(intree[query[i].end])
         query[i].weight=min(w[x],w[query[i].end]);
}*/
void dfs(int x,int y,int father,int minw)
{
     register int i;
     if(x==y){
       ans=minw;
       return;
     }
     for(i=last[x];i;i=edge[i].next)
       if(edge[i].end!=father&&ans==-1)
         dfs(edge[i].end,y,x,min(edge[i].weight,minw));
}
inline void solve()
{
       Kruskal();
       register int i;
       for(i=1;i<=q;i++){
         ans=-1;dfs(query[i].start,query[i].end,-1,maxint);
         query[i].weight=ans;
       }
       for(i=1;i<=q;i++)
         printf("%d\n",query[i].weight);
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    init();
    solve();
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0;
}
/*
4 3
1 2 4
2 3 3
3 1 1
3
1 3
1 4
1 3

*/
