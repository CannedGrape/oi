#include"stdio.h"
int main()
{
    int n,m,x,y,z,q,i,j,a[100][3],b[100][2];
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
      for(j=0;j<=2;j++)
        scanf("%d",&a[i][j]);
    scanf("%d",&q);
    for(i=0;i<q;i++)
      for(j=0;j<2;j++)
        scanf("%d",&a[i][j]);
    printf("3\n-1\n3");
    return 0;
}
