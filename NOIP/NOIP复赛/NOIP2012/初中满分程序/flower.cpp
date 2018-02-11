#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,x[101],f[101][101];
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
    for(i=0;i<=n;i++)
      f[i][0]=1;
    for(i=1;i<=m;i++)
      f[0][i]=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        {
         f[i][j]=0;
         for(k=0;k<=min(j,x[i]);k++)
           f[i][j]=(f[i][j]+f[i-1][j-k])%1000007;
        }
    printf("%d\n",f[n][m]);
    fclose(stdin);
    fclose(stdout);
    system("pause");
    return 0;
}
