#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,tot,a[100001],b0,b[100001],b1[100001],ans;
bool p[100001];
int solve()
{
    int i;
    i=1;b0=0;
    while (i<tot)
    {
      if (a[i+1]>a[i])
      {
        b0++;b[b0]=a[i];b1[b0]=i;
        while (a[i+1]>a[i]&&i<tot)
          i++;
      }
      else
      {
        b0++;b[b0]=a[i];b1[b0]=i;
        while (a[i+1]<a[i]&&i<tot)
          i++;
      }
    }
    b0++;
    b[b0]=a[tot];b1[b0]=tot;
    ans=b0;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,x;
    cin>>n;
    tot=0;a[0]=-1;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&x);
      if (x!=a[tot])
      {
        tot++;
        a[tot]=x;
      }
    }
    solve();
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
