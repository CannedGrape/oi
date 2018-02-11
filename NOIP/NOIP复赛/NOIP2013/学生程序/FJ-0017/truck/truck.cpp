#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define ifn(x) if(!x)
using namespace std; 
typedef long long ll;
const ll llinf=0x7fffffffffffffffll;
const int inf=0x3fffffff,upinf=0x7fffffff;
const double dinf=1e20,eps=1e-12;

int n,m,q;
struct oEdge
{
       int a,b,v;
}oedge[50001];
int oe_len=0;
void addoedge(int a, int b, int v)
{
     oedge[++oe_len].a=a;
     oedge[oe_len].b=b;
     oedge[oe_len].v=v;
}
struct Question
{
       int f,t;
}que[30001];
void Init()
{
     scanf("%d%d",&n,&m);
     int a,b,v; rep(i,1,m) scanf("%d%d%d",&a,&b,&v),addoedge(a,b,v);
     scanf("%d",&q);
     rep(i,1,q) scanf("%d%d",&que[i].f,&que[i].t);
}
struct Edge
{
       int f,t,v;
       Edge *p,*opp;
}edge[20010],*list[10001];
int e_len=1;
void add_edge(int f, int t, int v)
{
     edge[++e_len].f=f;
     edge[e_len].t=t;
     edge[e_len].v=v;
     edge[e_len].p=list[f];
     edge[e_len].opp=&edge[(e_len^1)];
     list[f]=&edge[e_len];
}
bool cmp(oEdge x,oEdge y)
{
     return x.v>y.v;
}
int father[10001];
int gf(int x)
{
    if(father[x] == x) return father[x];
    else         
                 {
                 father[x]=gf(father[x]);
                 return father[x];
                 }
}
int itedge=0;
void merge(oEdge x)
{
     int fa=gf(x.a),fb=gf(x.b);
     if(fa != fb)
           {
           itedge++;
           add_edge(x.a,x.b,x.v);
           add_edge(x.b,x.a,x.v);
           father[fa]=fb;
           }
}
void Kruskal()
{
     rep(i,1,n) father[i]=i;
     sort(oedge+1,oedge+oe_len+1,cmp);
     rep(i,1,oe_len)
                    {
                    if(itedge == n-1) break;
                    merge(oedge[i]);
                    }
}
struct Point
{
       int f[15],sp[15],d,setn;
}point[10001];
int sett[10001],sett_len=0;
bool settroot[10001];
void Lca_Init()
{
     memset(settroot,0,sizeof(settroot));
     rep(i,1,n) point[i].setn=gf(i);
     rep(i,1,n) ifn(settroot[point[i].setn]) sett[++sett_len]=point[i].setn;
      
     rep(i,1,n) 
                {
                rep(j,0,15) 
                            point[i].f[j]=-1,point[i].sp[j]=inf;
                point[i].d=-1;
                }
}
void Dfs(int node,int deep)
{
     point[node].d=deep;
     for(Edge *i=list[node];i;i=i->p)
              {
              if(i->v != -1)
                      {
                      i->opp->v=-1;
                      Dfs(i->t,deep+1);
                      }
              }
}
queue<int>bfsque;
int order[10001],o_len=0;
void Bfs(int root)
{
     o_len=0;
     int i;
     bfsque.push(root);
     while(!bfsque.empty())
                        {
                        i=bfsque.front();
                        bfsque.pop();
                        order[++o_len]=i;
                        for(Edge *j=list[i];j;j=j->p)
                                if(j->v!=-1) point[j->t].f[0]=i,point[j->t].sp[0]=j->v,bfsque.push(j->t);
                        }
}
void getbinary()
{
     rep(i,1,o_len)
                   {
                   if(point[order[i]].f[0] == -1 )break;
                   rep(j,1,15)
                              {
                              if(point[order[i]].f[j-1]==-1) break;
                              point[order[i]].f[j]=point[point[order[i]].f[j-1]].f[j-1];
                              point[order[i]].sp[j]=min(point[point[order[i]].f[j-1]].sp[j-1],point[order[i]].sp[j-1]);
                              }
                   }
}   
void Lca_P()
{
     rep(i,1,sett_len)
          {
          Dfs(sett[i],1);
          Bfs(sett[i]);
          getbinary();
          }
}
void Answer()
{
     rep(i,1,q)
               {
               int minn=inf;
               int pf=que[i].f,pt=que[i].t;
               if(point[pf].setn != point[pt].setn) {printf("-1\n"); continue;}
               while(point[pf].d>point[pt].d)
               {
                minn=min(minn,point[pf].sp[0]);
                pf=point[pf].f[0];
                }
               while(point[pf].d<point[pt].d)
               {
                minn=min(minn,point[pt].sp[0]);
                pt=point[pt].f[0];
                }
               if(point[pf].f[0]!=point[pt].f[0])
               {                             
               while(1)
               {
                       int i=0;
                       while(point[pf].f[i] != point[pt].f[i]) i++;
                       i--;
                       if(i==-1) 
                                 {
                                 minn=min(minn,point[pf].sp[0]);
                                 minn=min(minn,point[pt].sp[0]);
                                 break;
                                 }
                       else
                       {
                       minn=min(minn,point[pf].sp[i]);
                       minn=min(minn,point[pt].sp[i]);
                       pf=point[pf].f[i];
                       pt=point[pt].f[i];
                       }
               }
               }
               printf("%d\n",minn);
               }
}
int main()
{
    freopen("truck.in","r",stdin); freopen("truck.out","w",stdout);
    Init();
    Kruskal();
    Lca_Init();
    Lca_P();
    Answer();
    fclose(stdin); fclose(stdout);
    return 0;
}
