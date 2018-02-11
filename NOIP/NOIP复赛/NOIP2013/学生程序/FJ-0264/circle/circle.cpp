#include <cstdio>
typedef long long ll;
ll ans,n,m,k,x;
ll mi(ll a,ll b){
	ll res=1;
	for (;b;b>>=1){
		if (b&1) res=res*a%n;
		a=a*a%n;
	}
	return res;
}
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	ans=(x+m*mi(10,k)%n)%n;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
}
