#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,k,x,ans;
long long sqr(long long x){return x*x%n;}
long long pow(long long a,long long b)
{
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2==1) return sqr(pow(a,b/2))*a%n;
    return sqr(pow(a,b/2));
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    ans=pow(10,k)*m%n;
    ans=(ans+x)%n;
    printf("%lld\n",ans);
    return 0;
}
