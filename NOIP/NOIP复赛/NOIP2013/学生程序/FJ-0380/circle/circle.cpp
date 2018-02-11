#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

typedef long long ll;
using namespace std;

ll qkpow(ll n,ll k,ll m){
	ll ans=1;
	while(k){
		if(k&1){ans=(ans*n)%m;}
		n=(n*n)%m;
		k>>=1;
	}
	return ans;
}
ll n,k,m,x;
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	
	cin>>n>>m>>k>>x;
	cout<<((m*qkpow(10,k,n))%n+x)%n<<endl;
	return 0;
}