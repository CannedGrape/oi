#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#define MXM 100100
#define MXN 1010
#define MXZ 100010
#define MXQ 1010
using namespace std;
struct node
{
       int v,w,last;
}elist[MXM];
int zh[MXN],tot;
void add(int u,int v,int w)
{
     elist[++tot].v=v;
     elist[tot].w=w;
     elist[tot].last=zh[u];
     zh[u]=tot;
}

int n,m;
int qur,st[MXQ],ed[MXQ];
void init()
{
     scanf("%d%d",&n,&m);
     for (int i=1;i<=m;i++)
     {
       int x,y,z;
       scanf("%d%d%d",&x,&y,&z);
       add(x,y,z);add(y,x,z);
     }
     scanf("%d",&qur);
     for (int i=1;i<=qur;i++)
       scanf("%d%d",&st[i],&ed[i]);
}
int q[MXN],head,tail;
bool vis[MXN];
bool check(int x,int ss,int tt)
{
     memset(vis,0,sizeof(vis));
     q[0]=ss;head=0;tail=1;
     vis[ss]=1;
     while (head<tail)
     {
       int uu=q[head++];
       for (int i=zh[uu];i;i=elist[i].last)
       {
         if (elist[i].w>=x)
         {
           int vv=elist[i].v;
           if (!vis[vv])
           {
             vis[vv]=1;
             q[tail++]=vv;
             if (vv==tt)  return 1;
           }
         }
       }
     }
     return 0;
}
void solve()
{
     for (int i=1;i<=qur;i++)
     {
       int mid,l=-1,r=MXZ;
       while (l<r-1)
       {
         mid=(l+r)/2;
         if (check(mid,st[i],ed[i]))  l=mid;
         else  r=mid;
       }
       if (l>-1)  printf("%d\n",l);
       else  printf("-1\n");
     }
}
int main ()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
