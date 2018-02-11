#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
long long i,j,k,n,m,f[1001][1001],q,s,z=100000;
int main()
{freopen("truck.in","r",stdin);
 freopen("truck.out","w",stdout);
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
       f[i][j]=2147483647*z;
 for(i=1;i<=m;i++)
    {scanf("%d%d",&j,&k);
     scanf("%d",&s);
     if(f[k][j]!=2147483647*z)f[k][j]=f[j][k]=max(f[k][j],s);
     else f[k][j]=f[j][k]=s;
    }
 for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          if(i!=j&&i!=k&&j!=i&&max(f[i][k],f[k][j])<2147483647*z)
            f[i][j]=max(f[i][j],min(f[i][k],f[k][j]));
 scanf("%d",&q);
 for(i=1;i<=q;i++)
    {scanf("%d%d",&j,&k);
     if(f[j][k]>=2147483647*z)
       printf("-1\n");
     else
       printf("%d\n",f[j][k]);
    }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
