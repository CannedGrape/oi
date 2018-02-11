#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
long long n,ans;
long long a[1000005];
int main()
{	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	long long i,j;
	scanf ("%lld",&n);
	for (i=1;i<=n;i++)
	 scanf ("%lld",&a[i]);
	for (i=1;i<=n;i++)
	{if (a[i]-a[i-1]>0)
	  ans+=a[i]-a[i-1];
	}
	printf ("%lld\n",ans);
	return 0;
} 
