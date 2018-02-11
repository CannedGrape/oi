#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 10010
using namespace std;
int f[N][N],vv[N][N];
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int n,m,i,j,k,z,v1,v2,ans,vv1,vv2;
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
      {scanf("%d%d%d",&v1,&v2,&z);
       if (f[v1][v2]==0)
         {f[v1][v2]=f[v2][v1]=z;
          vv[v1][0]++;
          vv[v1][vv[v1][0]]=v2;
          vv[v2][0]++;
          vv[v2][vv[v2][0]]=v1;
         }
       else if (f[v1][v2]<z) f[v1][v2]=f[v2][v1]=z;
      }
    if (n<1000)
      {for (k=1;k<=n;k++)
         for (i=1;i<=n;i++)
           for (j=1;j<=n;j++)
            {if (f[i][k]>0 && f[k][j]>0)
               {ans=min(f[i][k],f[k][j]);
                f[i][j]=max(f[i][j],ans);
               }
            }
      }
    else
      {for (k=1;k<=n;k++)
         for (i=1;i<=vv[k][0];i++)
           for (j=1;i!=j && j<=vv[k][0];j++)
             {vv1=vv[k][i];
              vv2=vv[k][j];
              if (f[vv1][k]>0 && f[k][vv2]>0)
                {ans=min(f[vv1][k],f[k][vv2]);
                 f[i][j]=max(f[i][j],ans);
                }
             }
      }    
    scanf("%d",&k);
    while (k--)
      {scanf("%d%d",&v1,&v2);
       if (f[v1][v2]==0) printf("-1\n");
       else printf("%d\n",f[v1][v2]);
      }      
    fclose(stdin);
    fclose(stdout);
    return 0;
}
