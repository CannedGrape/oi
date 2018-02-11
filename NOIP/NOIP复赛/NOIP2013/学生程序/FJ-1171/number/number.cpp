#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n,Mod,Max,pd,End,sum,a[1000001];
long long ans,Max2,f[1000001],tz[1000001];
int main()
{
 freopen("number.in","r",stdin);
 freopen("number.out","w",stdout); 
 scanf("%d%d",&n,&Mod);
 for (int i=0;i<n;i++)
  scanf("%lld",&a[i]);
 Max=a[0];
 pd=0;
 tz[0]=a[0];
 for (int i=1;i<n;i++)
 {
  if (a[i]<0) {pd=1;End=i;}
  if (pd)
  if (Max>a[i])
  {
   sum=0;
   for (int j=i;j>=End;j--) sum+=a[j];
   if (sum>=0)
   {
    Max+=sum;
    pd=0;
    tz[i]=Max;
   }
   else tz[i]=Max;
  }
   else 
  {
   sum=0;
   for (int j=i;j>=End;j--) sum+=a[j];
   if (sum>=0)
   {
    Max+=sum;
    pd=0;
   }
   if (Max>a[i])
   tz[i]=Max;
   else {tz[i]=a[i];Max=a[i];}
  }
  else 
  {
  if (a[i]>=0) Max+=a[i];
  tz[i]=Max;
  }
}
 f[0]=tz[0];
 f[1]=f[0]+tz[0];
 Max2=f[0];
 for(int i=2;i<n;i++)
 {
 if(f[i-1]+tz[i-1]>Max2) Max2=f[i-1]+tz[i-1];
 f[i]=Max2;
 }
 ans=f[0];
 for (int i=1;i<n;i++)
 if (f[i]>ans) ans=f[i];
 printf("%lld\n",ans%(long long)Mod);
}

