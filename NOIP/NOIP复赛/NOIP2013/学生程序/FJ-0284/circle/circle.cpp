#include<cstdio>
long long ans,lei=10,n,m,k,x;
int main(){
	freopen("circle.in" ,"r",stdin );
	freopen("circle.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	ans=m % n;
	x  =x % n;
	while (k){
		if (k% 2) ans=(ans*lei)%n;
		    k/=2; lei=(lei*lei)%n;
	}
	ans=(ans+x)%n;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
}
