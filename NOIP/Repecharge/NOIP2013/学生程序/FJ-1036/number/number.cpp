#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

long long a[1000001],b[1000001],c[1000001];
long long Max(long long a,long long b)
{
     return a>b?a:b;
}

int main ()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(b,-1,sizeof(b));
    long long m,n;
    scanf("%I64d%I64d",&n,&m);
    for (int i=1; i<=n; ++i)
      scanf("%I64d",&a[i]);
    b[1]=a[1];
    for (int i=2; i<=n; ++i)
      b[i]=Max(a[i]+b[i-1],b[i]);
    c[1]=b[1];
    for (int i=2; i<=n; ++i)
      c[i]=c[i-1]+b[i-1];
    sort(c+1,c+1+n);
    printf("%I64d",c[n]%m);
    fclose(stdin); fclose(stdout);
}
