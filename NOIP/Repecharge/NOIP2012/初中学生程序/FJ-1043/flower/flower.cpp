#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long n,m,a[101],ans=0,yh[101][101];
long long dt(long long zl,long long wz)
{
    long long i,total=0;
    if (wz==0&&zl==0)  return 1;
    if (wz<0)  return 0;
    if (zl==0)   return 0;
    if (yh[zl][wz]==0)
    {
      for (i=0;i<=a[zl];i++)
        total=(total+dt(zl-1,wz-i))%1000007;
      yh[zl][wz]=total%1000007;
      return yh[zl][wz];
    }
    else
      return yh[zl][wz];
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    long long i;
    cin>>n>>m;
    for (i=1;i<=n;i++)
      cin>>a[i];
    ans=dt(n,m);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
