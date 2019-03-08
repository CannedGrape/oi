#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define N 100010
using namespace std;
int h[N],f[N][5];
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,n,j,ans;
    ans=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&h[i]);
    for (i=1;i<=n;i++)
      {f[i][1]=f[i][2]=1;
       for (j=1;j<i;j++)
         {if (h[j]<h[i])
            {f[i][2]=max(f[j][3]+1,f[i][2]);
             f[i][4]=max(f[j][1]+1,f[i][4]);
            }
          else if (h[j]>h[i])
                 {f[i][1]=max(f[j][4]+1,f[i][1]);
                  f[i][3]=max(f[j][2]+1,f[i][3]);
                 }
         }
       for (j=1;j<=4;j++) ans=max(ans,f[i][j]);
      }
    printf("%d\n",ans);  
    fclose(stdin);
    fclose(stdout);
    return 0;
}
