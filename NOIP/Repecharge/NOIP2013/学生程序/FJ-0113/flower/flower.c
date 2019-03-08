#include<stdio.h>
#include<stdlib.h>
int n,g[100010];
int f[100010][2]={};
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,ok=0,j;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++) scanf("%d",&g[i]);
    for(i=2;i<=n;i+=2)
    {
        if((g[i]<=g[i+1]&&g[i]>=g[i-1])||(g[i]<=g[i-1]&&g[i]>=g[i+1]))
        {
            ok=1;
            break;
        }
    }
    if(ok==0)
    {
        printf("%d\n",n);
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        f[i][0]=f[i][1]=1;
        for(j=1;j<i;j++)
        {
            if(g[j]<g[i])
            {
                f[i][0]=max(f[i][0],f[j][1]+1);
            }
            if(g[j]>g[i])
            {
                f[i][1]=max(f[i][1],f[j][0]+1);
            }
        }
    }
    printf("%d\n",max(f[n][0],f[n][1]));
    return 0;
}
