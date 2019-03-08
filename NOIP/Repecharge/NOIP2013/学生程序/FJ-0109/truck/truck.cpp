#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct edge{
       int u,v,d;
}e[100010];

int n,m,q,sz,fa[10010];
int pre[100010],last[10010],to[100010],dd[100010];

bool cmp (edge a,edge b)
{
     return a.d>b.d;
}

int getfa (int a)
{
    if (fa[a]==a) return a;
    return fa[a]=getfa(fa[a]);
}

void ins (int u,int v,int w)
{
     pre[++sz]=last[u];
     to[sz]=v;
     dd[sz]=w;
     last[u]=sz;
     
     pre[++sz]=last[v];
     to[sz]=u;
     dd[sz]=w;
     last[v]=sz;
     
}

int qq[2000010];
bool v[20010];

void doing (int s,int t)
{
     memset (v,0,sizeof(v));
     memset (qq,0,sizeof(qq));
     qq[1]=s;
     v[1]=1;
     int head,tail;
     head=1;
     tail=1;
     int now;
     int ans=2147483;
     while (head<=tail)
     {
       now=qq[head];
       if (now==t)  break;
       int i=last[now];
       while (i!=0)
       {
         if (!v[to[i]])
         {
           //cout<<dd[i]<<" ";
           v[to[i]]=1;
           if (ans>dd[i]) ans=dd[i];
           qq[++tail]=to[i];
         }
         i=pre[i];
       }
       head++;
     }
     cout<<ans<<endl;
}

void init ()
{
     int i,s,t;
     sz=0;
     cin>>n>>m;
     for (i=1;i<=n;i++)  fa[i]=i;
     int a,b,c;
     for (i=1;i<=m;i++)
     {
       scanf ("%d%d%d",&a,&b,&c);
       e[++sz].u=a;e[sz].v=b;e[sz].d=c;
       e[++sz].u=b;e[sz].v=a;e[sz].d=c;
       //cout<<e[sz-1].u<<" "<<e[sz-1].v<<" "<<e[sz-1].d<<endl;
     }
     m=m*2;
     sort (e+1,e+1+m,cmp);
     sz=0;
     for (i=1;i<=m;i++)
     {
         int tx=getfa(fa[e[i].u]);
         int ty=getfa(fa[e[i].v]);
         if (tx!=ty)
         {
           //cout<<tx<<" "<<ty<<endl;
           fa[ty]=fa[tx];
           //cout<<tx<<" "<<ty<<endl;
           ins (e[i].u,e[i].v,e[i].d);
         }
     }
     cin>>q;
     for (i=1;i<=q;i++)
     {
       scanf ("%d%d",&s,&t);
       if (getfa(s)!=getfa(t))
         printf ("-1\n");
       else
         doing (s,t);
       //cout<<getfa(s)<<" "<<getfa(t)<<endl;
     }
}

int main ()
{
    freopen ("truck.in","r",stdin);
    freopen ("truck.out","w",stdout);
    init ();
    //system ("pause");
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
