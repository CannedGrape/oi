#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,x,k;

long long qpow(int v)
{
	if (v==0) return 1;
	if (v==1) return 10;
	long long t=qpow(v/2);
	if (v%2==0) return t*t%n;
	else return t*t*10%n;
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%lld\n",(x+qpow(k)*m%n)%n);
	return 0;
}

