#include<cstdio>
using namespace std;
long long i,j,k,n,m,x;
long long pow(int k)
{
     if (k==1) return (10%n);
     long long tmp;
     tmp=pow(k/2);
     tmp=(tmp*tmp)%n;
     if (k%2==1) return (tmp*10)%n;
     else if (k%2==0)
         return tmp;
}

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    long long ans;
    ans=pow(k)%n;
    ans=(ans*m)%n;
    ans=(ans+x)%n;
    printf("%lld\n",ans);
    //while (1);
    return 0;
}
