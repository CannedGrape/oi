#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;
long long quickpow(long long m,long long n,long long q)
{
	long long ans=1;
	while(n)
	{
		if(n&1) ans=(ans%q)*m%q; 
		n=n>>1;
		m=m%q*m%q;
	}
	return ans;
}
long long n,m,k,x;
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	 cin>>n>>m>>k>>x;
	 cout<<(x%n+m%n*quickpow(10,k,n)%n)%n;
	return 0;
}
