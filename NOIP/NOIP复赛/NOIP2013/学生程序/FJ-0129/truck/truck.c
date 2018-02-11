#include<stdio.h>
int n,m,q;
int f[1010][1010]={0};
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    int i,j,k,x,y,z,t;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x>y)
        {
            t=x;
            x=y;
            y=t;
        }
        if(z>f[x][y])f[x][y]=z;
    }
    int temp;
    for(i=1;i<=n-1;i++)
    {
        for(j=i+2;j<=n;j++)
        {
            for(k=i+1;k<=j-1;k++)
            {
                if(f[i][k]!=0&&f[k][j]!=0)
                {
                    if(f[i][k]<f[k][j])temp=f[i][k];
                    else temp=f[k][j];
                    if(temp>f[i][j])f[i][j]=temp;
                }
            }
        }
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        if(x>y)
        {
            t=x;
            x=y;
            y=t;
        }
        if(f[x][y]==0)f[x][y]=-1;
        printf("%d\n",f[x][y]);
    }
    return 0;
}
