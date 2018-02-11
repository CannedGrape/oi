#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=35;
const int inf=1000000000;
const int dx[5]={0,0,1,0,-1};
const int dy[5]={0,1,0,-1,0};

int n,m,Q,ex,ey,sx,sy,tx,ty,ans;
int A[maxn][maxn],dist[maxn][maxn][maxn][maxn];

struct Queue
{
       int x1,y1,x2,y2;
       Queue(){};
       Queue(int _x1,int _y1,int _x2,int _y2) {x1=_x1; y1=_y1; x2=_x2; y2=_y2;}
}q[maxn*maxn*maxn*maxn];

void init()
{
     scanf("%d %d %d",&n,&m,&Q);
     for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++) scanf("%d",&A[i][j]);
}

void bfs()
{
     memset(dist,255,sizeof(dist));
     int head=1,tail=2; q[head]=Queue(sx,sy,ex,ey); dist[sx][sy][ex][ey]=0;
     while(head<tail)
     {
           int x1=q[head].x1,y1=q[head].y1,x2=q[head].x2,y2=q[head].y2;
           for(int k=1;k<=4;k++)
           {
               int vx=x2+dx[k],vy=y2+dy[k];
               if(vx<1 || vx>n || vy<1 || vy>m || !A[vx][vy] || (vx==x1 && vy==y1)) continue;
               if(dist[x1][y1][vx][vy]==-1)
                  dist[x1][y1][vx][vy]=dist[x1][y1][x2][y2]+1,q[tail++]=Queue(x1,y1,vx,vy);
               vx=x1+dx[k],vy=y1+dy[k];
               if(vx<1 || vx>n || vy<1 || vy>m) continue;
               if(vx==x2 && vy==y2 &&  dist[x2][y2][x1][y1]==-1)
                  dist[x2][y2][x1][y1]=dist[x1][y1][x2][y2]+1,q[tail++]=Queue(x2,y2,x1,y1);
           }
           head++;
     }
}

void work()
{
     for(int i=1;i<=Q;i++)
     {
         scanf("%d %d %d %d %d %d",&ex,&ey,&sx,&sy,&tx,&ty);
         if(sx==tx && sy==ty) {printf("0\n"); continue;}
         if(!A[sx][sy] || !A[tx][ty]) {printf("-1\n"); continue;}
         bfs(); ans=inf;
         for(int k=1;k<=4;k++)
         {
             int vx=tx+dx[k],vy=ty+dy[k];
             if(vx<1 || vx>n || vy<1 || vy>m) continue;
             if(dist[tx][ty][vx][vy]!=-1) ans=min(ans,dist[tx][ty][vx][vy]);
         }
         if(ans==inf) ans=-1;
         printf("%d\n",ans);
     }
}

int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    work();
    return 0;
}

