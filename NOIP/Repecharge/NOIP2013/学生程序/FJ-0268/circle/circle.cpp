#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long long n,m,x,k;
void ksm(long long t){
	long long gg=10,ll=10;
	while(t>0){
		if (t%2==1) {
			gg=gg*ll%n;
		}
		t/=2;
		gg=gg*gg%n;
		//cout<<gg<<"  "<<t<<endl;
	}
	m=m*gg%n;
}
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	if (k-1>=0) ksm(k-1);
	x=x+m;
	x%=n;
	cout<<x<<endl;
	fclose(stdin);
	fclose(stdout);
}
