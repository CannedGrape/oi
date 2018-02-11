#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  int n;
  scanf("%d",&n);
  int i,j,k,a[n],max_h=0;
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
    if(a[i]>max_h)
      max_h=a[i];
  }
  int X[n+1][2],Xn=1,x[n+1][2],xn,l,ans=0;
  X[0][0]=0;
  X[0][1]=n-1;
  for(i=1;i<=max_h;i++)
  {
    xn=0;
    for(j=0;j<Xn;j++)
    {
      l=n;
      for(k=X[j][0];k<=X[j][1];k++)
        if(a[k]>=i)
        {
          if(l==n)
            l=k;
        }
        else
        {
          x[xn][0]=l;
          x[xn][1]=k-1;
          xn++;
          l=n;
        }
    }
    if(l!=n)
    {
      x[xn][0]=l;
      x[xn][1]=k-1;
      xn++;
    }
    for(j=0;j<xn;j++)
    {
      X[j][0]=x[j][0];
      X[j][1]=x[j][1];
    }
    Xn=xn;
    ans+=Xn;
  }
  printf("%d",ans);
//  system("pause");
  fclose(stdin);
  fclose(stdout);
  return 0;
}
