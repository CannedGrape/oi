#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n,m,q;
int map[50][50]={};
int tx,ty,sx,sy,ex,ey;
short vis[31][31][31][31]={};
int ans;
void dfs(int x,int y,int xx,int yy,int sum)
{
    int i,j;
    if(xx==ex&&yy==ey)
    {
        if(ans>sum) ans=sum;
        return;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(map[i][j]==1)
            {
                if(abs(i-x)+abs(j-y)==1&&vis[i][j][x][y]==0)
                {
                    vis[i][j][x][y]=1;
                    if(i==xx&&j==yy)
                    {
                        dfs(i,j,x,y,sum+1);
                    }
                    else
                    {
                        dfs(i,j,xx,yy,sum+1);
                    }
                }
            }
        }
    }
}
void s()
{
    memset(vis,0,sizeof(vis));
    ans=99990;
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(map[i][j]==1)
            {
                if(abs(i-tx)+abs(j-ty)==1)
                {
                    dfs(i,j,sx,sy,1);
                }
            }
        }
    }
    if(ans!=99990) printf("%d\n",ans);
    else printf("-1\n");
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d%d%d%d",&tx,&ty,&sx,&sy,&ex,&ey);
        if(sx==ex&&sy==ey)
        {
            printf("0\n");
            continue;
        }
        s();
    }
    return 0;
}
