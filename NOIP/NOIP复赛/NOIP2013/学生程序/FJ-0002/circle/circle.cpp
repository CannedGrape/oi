#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

long long n, m, k, x, kk;

long long QuickPow(long long a, long long b, long long p)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
}

int main()
{
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	cin >> n >> m >> k >> x;
	kk = QuickPow(10, k, n);
	cout << (x + m * kk) % n << endl;
	return 0;
}
