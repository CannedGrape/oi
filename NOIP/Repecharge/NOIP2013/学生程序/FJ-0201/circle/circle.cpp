#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

long long qpow(long long n,long long m,long long mo){
	int q=n,ans=1;
	while (m){
		if (m&1){
			ans=(ans*q)%mo;
		}
		q=(q*q)%mo;
		m>>=1;
	}
	return ans;
}
long long n,m,k,x;
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n>>m>>k>>x;
	long long zero=(m*qpow(10,k,n))%n;
	cout<<(zero+x)%n;
	return 0;
}
