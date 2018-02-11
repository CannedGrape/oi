#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m,k,x;
ll Pow(ll k,int t)
{
	ll sum=k,ans=1;
	for (;t;t>>=1)
	{
		if (t&1) ans=(ans*sum)%n;
		sum=(sum*sum)%n;
	}
	return ans;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	ll t; t=(ll)Pow(10,k)*m%n; t=(t+x)%n;
	printf("%d\n",t);
	return 0;
}

