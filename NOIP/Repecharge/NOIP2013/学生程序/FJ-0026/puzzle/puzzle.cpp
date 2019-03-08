#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<algorithm>
using namespace std;
int map[31][31],yd[5][2],dl[20000][5],n,m;
int zhan[1000][3];
int ex,ey,sx,sy,tx,ty;
int dis[31][31];
int wy[31][31];
bool vis[31][31];
bool zou[31][31];
int bfs(int x,int y,int tx,int ty)
{
    int head=0,tail=1;
    memset(wy,127/3,sizeof(wy));
    memset(zou,false,sizeof(zou));
    wy[x][y]=0;
    zhan[1][0]=x;
    zhan[1][1]=y;
    zou[x][y]=true;
    while(head<tail)
    {
                    head++;
                    int temx,temy;
                    temx=zhan[head][0];temy=zhan[head][1];
                    for(int i=1;i<=4;i++)
                    {
                            int zx,zy;
                            zx=temx+yd[i][0];zy=temy+yd[i][1];
                            if(zx>=1&&zx<=n&&zy>=1&&zy<=m&&!zou[zx][zy]&&map[zx][zy])
                            {
                             wy[zx][zy]=wy[temx][temy]+1;
                             tail++;
                             zhan[tail][0]=zx;
                             zhan[tail][1]=zy;                                           
                            zou[zx][zy]=true;
                            if(zx==tx&&zy==ty)
                            goto xx;
                            }
                            }
                    }
    xx:;
    return wy[tx][ty]+1;
    }
void moni()
{
     memset(dis,127/3,sizeof(dis));
     vis[sx][sy]=true;
     dis[sx][sy]=0;
     int head=0,tail=1;
     dl[1][0]=sx;dl[1][1]=sy;
     dl[1][2]=ex;dl[1][3]=ey;
     while(head<tail)
     {
                     head++;
                     int temx,temy;
                     temx=dl[head][0];temy=dl[head][1];
                     map[temx][temy]=0;
                     for(int i=1;i<=4;i++)
                     {
                             int x,y;
                             x=temx+yd[i][0];y=temy+yd[i][1];
                             if(x>=1&&x<=n&&y>=1&&y<=m&&map[x][y])
                             {
                             int xxx=bfs(x,y,dl[head][2],dl[head][3]);
                             if(dis[temx][temy]+xxx<dis[x][y])
                             {
                              dis[x][y]=dis[temx][temy]+xxx;
                              if(!vis[x][y])
                              {
                                            tail++;
                                            dl[tail][0]=x;dl[tail][1]=y;
                                            dl[tail][2]=temx;dl[tail][3]=temy;
                                            vis[x][y]=true;
                                            }                                                                          
                                            }
                             }
                             }
                     map[temx][temy]=1;
                     vis[temx][temy]=false;
                     }
     if(dis[tx][ty]<1e08)
     cout<<dis[tx][ty]<<endl;
     else cout<<-1<<endl;
     return;
     }
int main()
{
    freopen("puzzle.in","r",stdin);freopen("puzzle.out","w",stdout);
    int q;
    {
        yd[1][0]=1;yd[2][1]=1;yd[3][1]=-1;yd[4][0]=-1;
        }
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      scanf("%d",&map[i][j]);
    for(int i=1;i<=q;i++)
    {
            scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
            moni();
            }
    fclose(stdin);fclose(stdout);
    return 0;
    }
