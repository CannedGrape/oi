#include<cstdio>
#include<cstring>
int n,m,p;
int dis[1001][1001];
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    memset(dis,-1,sizeof(dis));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    if (dis[x][y]<z)dis[x][y]=dis[y][x]=z;    
    }
    for (int k=1;k<=n;++k)
      for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
          if (k!=i&&k!=j&&i!=j)
            dis[i][j]=dis[i][k]<dis[k][j]?(dis[i][j]>dis[i][k]?dis[i][j]:dis[i][k]):(dis[i][j]>dis[k][j]?dis[i][j]:dis[k][j]);
    scanf("%d",&p);
    for (int i=1;i<=p;++i)
    {
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d\n",dis[x][y]);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
