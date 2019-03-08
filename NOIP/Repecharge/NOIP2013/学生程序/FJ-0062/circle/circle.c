#include"stdio.h"
long long m,n,k,x,yu,ret=1,a=10;
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    yu=n*gcd(m,n);
    while(k>0)
    {
		if(k%2==1)ret=ret*a%yu;
		a=a*a%yu;
		k/=2;
	}
	printf("%lld\n",(x+ret*m)%n);
	return 0;
}
    
