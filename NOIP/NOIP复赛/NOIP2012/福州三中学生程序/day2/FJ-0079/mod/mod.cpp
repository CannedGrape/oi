#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,b,a) for(int i=(b);i>=(a);i--)
#define fe(e,x) for(edge *e = (x)->first;e;e = e->next)
#define mk(a,b) make_pair((a),(b))
ll a,b;
ll getinv(ll a,ll b){
	ll mod = b;
	ll c = a%b,q = a/b,k1 = 1,k2 = 0,k3 = (k1-q*k2%mod)%mod;
	while(c^1) a = b,b = c,c = a%b,q = a/b,k1 = k2,k2 = k3,k3 = (k1-q*k2%mod)%mod;
	return (k3%mod+mod)%mod;
}
void Init(){
	scanf("%lld%lld",&a,&b);
}
void solve(){
	printf("%lld\n",getinv(a,b));
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);

	Init();
	solve();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
