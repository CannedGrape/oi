#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int i,j,k,n,w[101],m,qy,zh,kk;
long long f[101][101];
bool p[101][101];
int main()
{freopen("culture.in","r",stdin);
 freopen("culture.out","w",stdout);
 scanf("%d%d%d%d%d",&n,&k,&m,&qy,&zh);
 for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
 for(i=1;i<=k;i++)
    for(j=1;j<=k;j++)
       scanf("%d",&p[i][j]);
 for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
       f[i][j]=2100000000;
 for(i=1;i<=m;i++)
    {scanf("%d%d%d",&j,&k,&kk);
     if(p[w[j]][w[k]]==0&&w[j]!=w[k])
       if(kk<f[k][j])
         f[k][j]=kk;
     if(p[w[k]][w[j]]==0&&w[j]!=w[k])
       if(kk<f[j][k])
         f[j][k]=kk;
    }
 for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          if(i!=j&&j!=k&&k!=i&&p[w[j]][w[i]]==0&&w[i]!=w[j]&&w[j]!=w[k]&&w[k]!=w[i])
            f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
 if(f[qy][zh]>=2100000000)
   printf("-1\n");
 else
   printf("%d\n",f[qy][zh]);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
