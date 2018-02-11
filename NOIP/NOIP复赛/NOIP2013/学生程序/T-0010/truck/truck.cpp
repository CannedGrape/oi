#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int g[2000][2000];
int Max(int X,int Y){return X>Y?X:Y;}
int Min(int X,int Y){return X<Y?X:Y;}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x][y]=g[y][x]=z;
    }
    for(int k=1;k<=n;++k)
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    g[i][j]=Max(g[i][j],Min(g[i][k],g[k][j]));
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;++i)
    {
        int xx,yy;
        scanf("%d%d",&xx,&yy);
        if(!g[xx][yy])g[xx][yy]--;
        printf("%d\n",g[xx][yy]);
    }
    fclose(stdin);fclose(stdout);
}
