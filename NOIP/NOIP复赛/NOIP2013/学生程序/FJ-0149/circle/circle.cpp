#include <cstdio>
long long n,m,k,x,s=1;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%lld %lld %lld %lld",&n,&m,&k,&x);
    for(int i=1;i<=k;i++)
      s*=10;
    printf("%lld\n",(x+s*m)%n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
    
