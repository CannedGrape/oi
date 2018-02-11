#include<cstdio>
#include<cstring>
using namespace std;
int n,m,q,ex,ey,sx,sy,tx,ty,head,tail;
int map[40][40];
int que[999999][5];
bool vis[40][40][40][40];
const int mo[4][2]={0,1,0,-1,1,0,-1,0};
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    int i,j;
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
       scanf("%d",&map[i][j]);
    while(q--)
    {
       scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
       head=0,tail=1;
       memset(vis,0,sizeof(vis));
       bool po=0;
       que[1][0]=ex;
       que[1][1]=ey;
       que[1][2]=sx;
       que[1][3]=sy;
       vis[ex][ey][sx][sy]=1;
       while(head<tail)
       {
           head++;
           int xx=que[head][0];
           int yy=que[head][1];
           int nx=que[head][2];
           int ny=que[head][3];
           for(int k=0;k<4;k++)
           {
               int x=xx+mo[k][0];
               int y=yy+mo[k][1];
               if(map[x][y]==0) continue;
               if((x!=nx||y!=ny)&&!vis[x][y][nx][ny])
               {
                  tail++;
                  que[tail][0]=x;
                  que[tail][1]=y;
                  que[tail][2]=nx;
                  que[tail][3]=ny;
                  que[tail][4]=que[head][4]+1;
                  vis[x][y][nx][ny]=1;
               }
               if(x==nx&&y==ny&&!vis[x][y][xx][yy])
               {
                  if(xx==tx&&yy==ty)
                  {
                    printf("%d\n",que[head][4]+1);
                    po=1;
                    break;                  
                  }
                  tail++;
                  que[tail][0]=x;
                  que[tail][1]=y;
                  que[tail][2]=xx;
                  que[tail][3]=yy;
                  que[tail][4]=que[head][4]+1;
                  vis[x][y][xx][yy]=1;
               } 
           }
           if(po) break;
       }
       if(!po) printf("-1\n");
    }
    return 0;
}
