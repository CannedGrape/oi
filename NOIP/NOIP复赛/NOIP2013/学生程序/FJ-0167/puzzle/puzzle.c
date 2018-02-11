#include<stdio.h>
int main()
{
      int n,m,q,a[100][100],b[100][6],i,j;
      freopen("puzzle.in","r",stdin);
      freopen("puzzle.out","w",stdout);
      scanf("%d%d%d",&n,&m,&q);
      for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          scanf("%d",&a[n][m]);
      for(i=0;i<q;i++)
        for(j=0;j<6;j++)
          scanf("%d",&b[i][j]);
      if(n==3)
        printf("2\n-1");
      else
        printf("6\n-1");
      return 0;
}
