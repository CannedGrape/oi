#include <cstdio>
typedef long long LL;
LL mod;
LL pow(LL x, LL y){
	if (y==0)
		return 1 % mod;
	if (y==1)
		return x % mod;
	int r = pow(x,y/2);
	if (y&1)
		return (((r*r) % mod)*x) % mod;
	else
		return (r*r) % mod;
}
int main(){
	LL n,m,k,x;
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	mod = n;
	LL pos = (x + (m * pow(10,k)) % mod) % mod;
	printf("%lld\n",pos);
}
