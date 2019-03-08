#include<cstdio>
int minn(int x,int y)
{
    if(x==-1)
        return y;
    if(y==-1)
        return x;
    return x<y?x:y;
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,j,k,n,m,a[1001][1001],x,y,z,q,minv[1001][1001];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        a[i][j]=-1;
        minv[i][j]=-1;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(a[x][y]<z)
        {
            a[x][y]=z;
            minv[x][y]=z;
        }
        if(a[y][x]<z)
        {
            a[y][x]=z;
            minv[y][x]=z;
        }
    }
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(minv[i][k]!=-1&&minv[k][j]!=-1)
        if(i!=j&&i!=k&&j!=k&&(minv[i][j]==-1||minn(minv[i][k],minv[k][j])>minv[i][j]))
        {
            minv[i][j]=minn(minv[i][k],minv[k][j]);
        }
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",minv[x][y]);
    }
    return 0;
}
