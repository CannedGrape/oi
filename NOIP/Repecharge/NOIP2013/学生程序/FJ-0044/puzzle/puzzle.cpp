#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct kk{int emp[3],org[3];}q[810010];
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0},sx,sy,tx,ty,ex,ey,n,m,map[31][31],ans[810010];
bool vis[31][31][31][31];
int BFS()
{
     int h=0,t=1;
     memset(vis,0,sizeof(vis));
     q[1].emp[1]=ex;q[1].emp[2]=ey;
     q[1].org[1]=sx;q[1].org[2]=sy;
     vis[ex][ey][sx][sy]=1;ans[1]=0;
     while (h<t)
     {
           h++;
           ex=q[h].emp[1];ey=q[h].emp[2];sx=q[h].org[1];sy=q[h].org[2];
           for (int i=0;i<=3;i++)
           {   
               int nowx=ex+xx[i],nowy=ey+yy[i];
               if (1<=nowx&&nowx<=n&&1<=nowy&&nowy<=m)
                  if (map[nowx][nowy]==1)
                  {
                    if (nowx==sx&&nowy==sy&&!vis[sx][sy][ex][ey])
                    {
                      vis[sx][sy][ex][ey]=1;
                      t++;ans[t]=ans[h]+1;
                      q[t].emp[1]=sx;q[t].emp[2]=sy;
                      q[t].org[1]=ex;q[t].org[2]=ey;
                      if (ex==tx&&ey==ty) return ans[t];
                    }
                    else 
                    if (!vis[nowx][nowy][sx][sy])
                    {  
                      vis[nowx][nowy][sx][sy]=1;
                      t++;
                      q[t].emp[1]=nowx;q[t].emp[2]=nowy;
                      q[t].org[1]=sx;q[t].org[2]=sy;
                      ans[t]=ans[h]+1;
                    }
                  }
           }
     }
     return -1;
}
int main()
{    
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j,q;
    scanf("%d%d%d",&n,&m,&q);
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        scanf("%d",&map[i][j]);
    for (i=1;i<=q;i++)
    {
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        if (sx==tx&&sy==ty) {printf("0\n");continue;}
        if (map[tx][ty]==0||map[sx][sy]==0) {printf("-1\n");continue;}
        printf("%d\n",BFS());        
    } 
    return 0;
}
