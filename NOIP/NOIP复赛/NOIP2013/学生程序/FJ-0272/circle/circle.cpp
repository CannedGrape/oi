#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<algorithm>
#define LL long long
LL n,m,k,x;
LL pow(LL a,LL b,LL r,LL c){
	LL ans=a,temp=b%c;
	while(r){
		if(r&1) ans=(ans*temp)%c;
		temp=(temp*temp)%c;
		r/=2;		
	}
	return ans;
}
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	printf("%lld",(x+pow(m,10,k,n))%n);
	return 0;
}

