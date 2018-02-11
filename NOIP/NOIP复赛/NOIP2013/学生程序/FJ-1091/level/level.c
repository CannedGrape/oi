#include<stdio.h>
int main()
{
    int n,m,i,j,a[100];
    int a1[100][100];
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
       scanf("%d",&a[i]);
       for(j=1;j<=a[i];j++)
          scanf("%d",&a1[i][j]);
    }
    printf("%d\n",m);
    return 0;
}
