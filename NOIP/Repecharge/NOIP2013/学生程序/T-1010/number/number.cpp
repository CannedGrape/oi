#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int d[1000000],s[1000000];
int main()
{
   int i,n,p,a,t,maxs;
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   scanf("%d%d",&n,&p);
   scanf("%d",&a);
   d[0]=a;
   for (i=1;i<n;i++)
   {
    scanf("%d",&a);
    d[i]+=max(d[i-1],d[i-1]+a);
    d[i]%=p;
   }
   s[0]=d[0];t=s[0]+d[0];maxs=s[0];
   for (i=1;i<n;i++)
   {
    if (d[i-1]+s[i-1]>t) t=d[i-1]+s[i-1];
	s[i]+=t;
	s[i]%=p;
    if (s[i]>maxs) maxs=s[i];
   }
   printf("%d\n",maxs%p);
  return 0;
}

