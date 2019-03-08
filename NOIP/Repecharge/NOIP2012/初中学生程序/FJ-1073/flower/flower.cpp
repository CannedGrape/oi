#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int i,j,k,f[101][101],a[101],n,m;
int main()
{freopen("flower.in","r",stdin);
 freopen("flower.out","w",stdout);
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
 f[0][0]=1;
 for(i=1;i<=n;i++)
    for(j=0;j<=m;j++)
       for(k=0;k<=a[i];k++)
          {f[i][j]+=f[i-1][j-k];f[i][j]%=1000007;}
 printf("%d\n",f[n][m]);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
