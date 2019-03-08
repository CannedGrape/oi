#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#define INF 0xfffffff
#define MXN 21
using namespace std;
struct game
{
       int l,r;
}dc[MXN];
int tot;
int  n,kl,kr;
bool vis[MXN];
int p,ans=INF;
void init()
{
     scanf("%d",&n);
     scanf("%d%d",&kl,&kr);
     for (int i=1;i<=n;i++)
       scanf("%d%d",&dc[i].l,&dc[i].r);
}
void dfs(int dep,int maxn)
{
     if (maxn>ans)  return;
     for (int i=1;i<=n;i++,tot++)
     {
       if (tot>10000000)  
       {
         printf("%d\n",ans);
         exit(0);
       }
       if (vis[i]==0)
       {
         vis[i]=1;
         p*=dc[i].l;
         if (dep<n)  dfs(dep+1,max(maxn,p/dc[i].l/dc[i].r));
         else  ans=min(max(maxn,p/dc[i].l/dc[i].r),ans);
         p/=dc[i].l;
         vis[i]=0;
       }
     }
}
int main ()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    init();
    p=kl;
    dfs(1,0);
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return 0;
}
