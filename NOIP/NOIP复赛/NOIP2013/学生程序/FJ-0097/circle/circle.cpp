//circle
#include<cstdio>
#include<cstring>

long long N,M,K,X,ans=10,cur=10;

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%lld%lld%lld%lld",&N,&M,&K,&X);
    while(K)
    {
            if(K&1) ans=(ans*cur)%N;
            cur=(cur*cur)%N;
            K=K>>1;
    }
    ans=(ans*M)%N;
    ans=(ans+X)%N;
    printf("%lld\n",ans);
    return 0;
}
