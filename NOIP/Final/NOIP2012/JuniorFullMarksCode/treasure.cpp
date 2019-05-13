#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int i,j,k,n,m,x[10001][101],s[10001],w,xx[10001][101];
bool b[10001][201];
long long ss;
int main()
{freopen("treasure.in","r",stdin);
 freopen("treasure.out","w",stdout);
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
    {for(j=1;j<=m;j++)
       {scanf("%d%d",&b[i][j],&x[i][j]);
       s[i]+=b[i][j];
       xx[i][j]=x[i][j];}
    for(j=m+1;j<=m*2;j++)
       b[i][j]=b[i][j-m];
    }
 scanf("%d",&w);w++;
 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
       x[i][j]=(x[i][j]-1)%s[i]+1;
 for(i=1;i<=n;i++)
    {k=0;ss+=xx[i][w];ss%=20123;
     for(j=w;j<=m*2&&k<x[i][w];j++)
        {k+=b[i][j];}j--;
     w=(j-1)%m+1;
    }
 printf("%d\n",ss);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
