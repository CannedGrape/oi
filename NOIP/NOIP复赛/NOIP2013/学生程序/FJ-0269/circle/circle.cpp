#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long n,m,k,x;
long long power(long long a,long long b)
{
	long long c = 1;
	while (b)
	{
		if (b & 1) c = (c * a) % n;
		a = (a * a) % n;
		b /= 2;
	}
	return c % n;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%lld %lld %lld %lld",&n,&m,&k,&x);
	long long   ans = (m * power(10,k)) % n;
	ans  = (ans + x) % n;
	cout << ans;
	fclose(stdin);fclose(stdout);
}