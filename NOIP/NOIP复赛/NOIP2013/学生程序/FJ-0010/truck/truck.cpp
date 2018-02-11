#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int beg[30001],en[30001],w[10001][10001];
int i,j,k,n,m,q,x,y,z;
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      for(j=i+1;j<=n;j++)
        w[i][j]=0;
    for(i=1;i<=m;i++)
    {
      scanf("%d%d%d",&x,&y,&z);
      if(x>y)
        swap(x,y);
      if(w[x][y]<z)
        w[x][y]=z;
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
      scanf("%d%d",&beg[i],&en[i]);
      if(beg[i]>en[i])
        swap(beg[i],en[i]);
    }
    for(i=1;i<=n;i++)
      for(j=i+1;j<=n;j++)
        for(k=i+1;k<=j-1;k++)
        {
          if(min(w[i][k],w[k][j])>w[i][j])
            w[i][j]=min(w[i][k],w[k][j]);
          if(min(w[i][j],w[k][j])>w[i][k])
            w[i][k]=min(w[i][j],w[k][j]);
          if(min(w[i][j],w[i][k])>w[k][j])
            w[k][j]=min(w[i][j],w[i][k]);
        }
    for(i=1;i<=q;i++)
      if(w[beg[i]][en[i]]>0)
        printf("%d\n",w[beg[i]][en[i]]);
      else
        printf("-1\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
