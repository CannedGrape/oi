#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long n,m,pz[10001][101],x,k=0,ans=0,lts,lg;
bool lt[10001][101];
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    long long i,j;
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
      for (j=0;j<m;j++)
        cin>>lt[i][j]>>pz[i][j];
    }
    cin>>j;
    for (i=1;i<=n;i++)
    {
      k=0;
      x=pz[i][j];
      ans=(ans+x)%20123;
      lts=0;
      for (lg=0;lg<m;lg++)
      {
        if (lt[i][lg]==1)
          lts++;
      }
      x=x%lts;
      if (x==0)
        x=lts;
      while (k!=x)
      {
        if (j==m)
          j=0;
        if (lt[i][j]==1)
          k++;
        j++;
      }
      j--;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
