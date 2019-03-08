#include<cstdio>

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int p10_mod(int k,int p){
	int res=1;
	for(int x=10;k;x=1LL*x*x%p,k>>=1) if (k&1) res=1LL*res*x%p;
	return res;
}

int n,m,k,o,c;
int main(){
	freopen("circle.in","r",stdin),freopen("circle.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&k,&o),c=n/gcd(n,m),k=p10_mod(k,c);
	printf("%d\n",(o+1LL*m*k)%n);
	return 0;
}
