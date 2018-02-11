#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,p,a[1000001],s[1000001],f[1000001],ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    a[0]=s[0]=f[0]=-INF;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
      {
      scanf("%d",&a[i]);
      s[i]=max(s[i-1],a[i]+s[i-1]);
      s[i]=max(s[i],a[i]);
      s[i]%=p;
      }
    f[1]=s[1];
    for(int i=2;i<=n;i++)
      f[i]=max(f[i-1],f[i-1]+s[i-1]),f[i]%=p;
    printf("%d\n",f[n]);
    return 0;
}
