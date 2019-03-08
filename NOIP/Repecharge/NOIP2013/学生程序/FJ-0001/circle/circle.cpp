#include<cstdio>
long long n,m,k,x;
long long power(long long s)
{
	if(s==0)
		return 1ll;
	long long tmp=power(s>>1);
	if(s&1)
		return (tmp*tmp*10ll)%n;
	else
		return (tmp*tmp)%n;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	printf("%lld\n",(x+m*power(k))%n);
	return 0;
}
