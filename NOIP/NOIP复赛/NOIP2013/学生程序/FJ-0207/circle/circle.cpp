#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
long long n,m,k,x;
long long s,p;
int main()
{	freopen ("circle.in","r",stdin);
	freopen ("circle.out","w",stdout);
	long long i,j;
	scanf ("%lld %lld %lld %lld",&n,&m,&k,&x);
	s=10;
	s=s%n;
	p=1;
	while(k>0)
	{if (k%2==1)
	  p*=s,p=p%n;
	 s=s*s;
	 s=s%n; 
	 k/=2;
	}
	p=p*m;
	p=p%n;
	x=x+p;
	x=x%n;
	printf ("%lld\n",x);
	return 0;
} 
