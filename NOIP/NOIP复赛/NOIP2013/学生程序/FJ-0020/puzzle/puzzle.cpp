#include<cstdio>
#include<cstring>
using namespace std;
int map[100][100],ex,ey,sx,sy,tx,ty;
int n,m,q,ans;
int flag=0,vis[100][100];
int ttx,tty,ssx,ssy,dx,dy;
void pd(int x,int y)
{
    if (flag) return;
    if (x==tx && y==ty)
    {
        flag=1;
        return;
    }
    vis[x][y]=1;
    if (x+1<=n && !vis[x+1][y] && map[x+1][y]) pd(x+1,y);
    if (x-1>=1 && !vis[x-1][y] && map[x-1][y]) pd(x-1,y);
    if (y+1<=m && !vis[x][y+1] && map[x][y+1]) pd(x,y+1);
    if (y-1>=1 && !vis[x][y-1] && map[x][y-1]) pd(x,y-1);
}


void dfs(int x,int y)
{
    if (x==ttx && y==tty) return;
    /*printf("%d %d---%d\n",x,y,vis[x][y]);
    printf("%d %d---%d\n",x+1,y,vis[x+1][y]);
    printf("%d %d---%d\n",x-1,y,vis[x-1][y]);
    printf("%d %d---%d\n",x,y+1,vis[x][y+1]);
    printf("%d %d---%d\n",x,y-1,vis[x][y-1]);*/
    if (x+1<=n && !vis[x+1][y] && map[x+1][y]) {vis[x+1][y]=vis[x][y]+1;dfs(x+1,y);}
    if (x-1>=1 && !vis[x-1][y] && map[x-1][y]) {vis[x-1][y]=vis[x][y]+1;dfs(x-1,y);}
    if (y+1<=m && !vis[x][y+1] && map[x][y+1]) {vis[x][y+1]=vis[x][y]+1;dfs(x,y+1);}
    if (y-1>=1 && !vis[x][y-1] && map[x][y-1]) {vis[x][y-1]=vis[x][y]+1;dfs(x,y-1);}
    
}

int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    memset(map,0,sizeof(map));
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&map[i][j]);
    while (q--)
    {
         scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
         if (map[tx+1][ty]+map[tx-1][ty]+map[tx][ty+1]+map[tx][ty-1]<=1)
             {puts("-1");continue;}
         for (int i=1;i<=n;i++)
         {
             for (int j=1;j<=m;j++)
             if (map[i][j] && (i!=tx || j!=ty))
             {
                 flag=0;
                 memset(vis,0,sizeof(vis));
                 vis[i][j]=1;
                 pd(sx,sy);
                 if (!flag){puts("-1");break;}
                 vis[i][j]=0;
             }
             if (!flag) break;
         }
         if (!flag) continue;
         
         memset(vis,0,sizeof(vis));
         ans=0;
         vis[sx][sy]=1;
         ttx=tx;tty=ty;
         dfs(sx,sy);
         ans=(vis[tx][ty]-2)*5;
         memset(vis,0,sizeof(vis));
         vis[sx][sy]=1;
         ttx=ex;tty=ey;
         dfs(sx,sy);
         ans+=vis[ex][ey]-2;
         printf("%d\n",ans);
    }
    //while (1);
    return 0;
}
         
         
             
    
