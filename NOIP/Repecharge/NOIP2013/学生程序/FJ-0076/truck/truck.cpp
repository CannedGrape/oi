#include<cstdio>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int w[1001][1001]={},f[1001][1001]={},n,m,q;
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    int a1,a2,a3;
    for(int j=1;j<=m;j++)
    {
      scanf("%d%d%d",&a1,&a2,&a3);
      w[a1][a2]=max(w[a1][a2],a3);
      w[a2][a1]=w[a1][a2];
    }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
        {if(w[i][k]>0)
           f[i][k]=1;
         if(w[i][j]>0&&w[j][k]>0&&min(w[i][j],w[j][k])>w[i][k])
           {f[i][k]=1;
           w[i][k]=min(w[i][j],w[j][k]);
           }
         }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
      {
      scanf("%d%d",&a1,&a2);
      if(f[a1][a2]==0)
        printf("-1\n");
      else
        printf("%d\n",w[a1][a2]);
      }
    //system("pause");
    return 0;
} 
/*
4 3 
1 2 4 
2 3 3 
3 1 1 
3 
1 3 
1 4 
1 3
*/
