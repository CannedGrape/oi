#include <stdio.h>
long long n,m,k,x;
long long power(long long num)
{
    long long base = 10,y = 1;
    for(;num;num>>=1)
    {
        if(num&1) y = (y*base)%n;
        base = (base*base)%n;
    }
    return y;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    k = power(k);
    m = (m*k)%n;
    printf("%lld\n",(x+m)%n);
    return 0;
}
