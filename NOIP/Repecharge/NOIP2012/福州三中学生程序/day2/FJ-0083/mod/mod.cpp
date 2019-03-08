#include <cstdio>
#include <cstdlib>

long long a,b;
/*
long long gcd(long long x, long long y)
{
	return y==0?x:(gcd(y,x%y));
}
*/
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	// printf("%lld\n",gcd(266,157));
	scanf("%lld%lld",&a,&b);
// a | b = 1
	long long i;
	for (i=1;(b*i+1) % a!=0;i++) ;
	printf("%lld\n",(b*i+1)/a);
	return 0;
	//
}
