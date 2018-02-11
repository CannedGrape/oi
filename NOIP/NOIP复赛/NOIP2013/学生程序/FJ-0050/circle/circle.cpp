#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long n,m,k,x,ans;
long long ksm(long long a,long long b)
{
     long long s=1;
     while (b)
     {
           if (b&1)
              s=(s*a)%n;
           a=(a*a)%n;
           b=b>>1;
     }
     return s;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    long long i;
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    i=ksm(10,k);
    ans=(x+(m%n)*i%n)%n;
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
