#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
using namespace std;
#define MXN 34
#define INF 100000000
struct node
{
       int x,y;
}UU,VV,EE;
struct node2
{
       int ux,uy,ex,ey;
};
int n,m,Q,tx,ty;
int num[MXN][MXN],dist[MXN][MXN],dist2[MXN][MXN];
int dx[5]={0,0,1,0,-1};
int dy[5]={0,1,0,-1,0};
node2 u,p;
queue <node2> q;
queue <node> qq;
void Init()
{
     scanf("%d%d%d",&n,&m,&Q);
     for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&num[i][j]);
}
int count_steps()//floodfill
{
    node uu2,pp2;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dist2[i][j]=INF;//
    uu2.x=u.ex;uu2.y=u.ey;qq.push(uu2);
    dist2[uu2.x][uu2.y]=0;
    while(!qq.empty())
      {
        uu2=qq.front();qq.pop();
        for(int i=1;i<=4;i++)
          {
            int tx2=uu2.x+dx[i],ty2=uu2.y+dy[i];
            if(tx2>=1&&tx2<=n&&ty2>=1&&ty2<=m&&num[tx2][ty2]==1&&(tx2!=u.ux||ty2!=u.uy)&&dist2[tx2][ty2]>dist2[uu2.x][uu2.y]+1)///
              {
                dist2[tx2][ty2]=dist2[uu2.x][uu2.y]+1;
                pp2.x=tx2;pp2.y=ty2;qq.push(pp2);
              }
          }
      }
    return dist2[tx][ty];
}
void find_ways()
{
     for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dist[i][j]=INF;
     u.ux=UU.x;u.uy=UU.y;u.ex=EE.x;u.ey=EE.y;dist[u.ux][u.uy]=0;q.push(u);
     while(!q.empty())
       {
         u=q.front();q.pop();
         for(int i=1;i<=4;i++)
           {
             tx=u.ux+dx[i];ty=u.uy+dy[i];
             if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&num[tx][ty]==1)
               {
                 int tmp=count_steps();
                 //printf("%d %d %d %d %d %d %d\n",u.ex,u.ey,tx,ty,u.ux,u.uy,tmp);
                 if(dist[tx][ty]>dist[u.ux][u.uy]+tmp+1)
                   {
                     dist[tx][ty]=dist[u.ux][u.uy]+tmp+1;
                     p.ux=tx;p.uy=ty;p.ex=u.ux;p.ey=u.uy;q.push(p);
                   }
               }
           }
       }
}
void solve()
{
     /*for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d ",num[i][j]);
     printf("\n");*/
     for(int i=1;i<=Q;i++)
       {
         scanf("%d%d%d%d%d%d",&EE.x,&EE.y,&UU.x,&UU.y,&VV.x,&VV.y);
         find_ways();
         if(dist[VV.x][VV.y]!=INF&&num[UU.x][UU.y]==1&&num[EE.x][EE.y]==1) printf("%d\n",dist[VV.x][VV.y]);///
         else printf("-1\n");
       }
}
int main()
{
    freopen("puzzle.in","r",stdin);freopen("puzzle.out","w",stdout);
    Init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
