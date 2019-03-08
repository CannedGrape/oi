#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,a[200000],a1[200000],b[200000],b1[200000],mo=99999997;
long long ans;
int px1(int l,int r)
{
    int i=l,j=r,k=a[(i+j)/2],t;
    do
    {
      while (a[i]<k) i++;
      while (a[j]>k) j--;
      if (i<=j)
      {
        t=a[i];a[i]=a[j];a[j]=t;
        t=a1[i];a1[i]=a1[j];a1[j]=t;
        i++;j--;
      }
    }
    while (i<j);
    if (i<r) px1(i,r);
    if (l<j) px1(l,j);
}
int px2(int l,int r)
{
    int i=l,j=r,k=b[(i+j)/2],t;
    do
    {
      while (b[i]<k) i++;
      while (b[j]>k) j--;
      if (i<=j)
      {
        t=b[i];b[i]=b[j];b[j]=t;
        t=b1[i];b1[i]=b1[j];b1[j]=t;
        i++;j--;
      }
    }
    while (i<j);
    if (i<r) px2(i,r);
    if (l<j) px2(l,j);
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int i;
    cin>>n;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      a1[i]=i;
    }
    for (i=1;i<=n;i++)
    {
      scanf("%d",&b[i]);
      b1[i]=i;
    }
    px1(1,n);
    px2(1,n);
    for (i=1;i<=n;i++)
    {
      ans+=abs(a1[i]-b1[i]);
      ans%=mo;
    }
    if (ans%2==0) ans=ans/2;
    else
      ans=(ans+mo)/2;
    ans%=mo;
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
