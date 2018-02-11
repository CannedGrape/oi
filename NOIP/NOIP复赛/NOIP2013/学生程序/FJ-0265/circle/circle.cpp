#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
typedef long long ll;

int _n, _m, _k, _x;
ll n, m, k, x;

ll power(ll a, ll nn)
{
	ll ans = 1;
	while (nn)
	{
		if (nn & 1) ans = (ans * a) % n;
		a = (a * a) % n;
		nn >>= 1;
	}
	return ans;
}

int main()
{
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	scanf("%d%d%d%d", &_n, &_m, &_k, &_x);
	n = _n, m = _m, k = _k, x = _x;
	printf("%d", (int)(((power(10, k) * m) % n + x) % n));
	fclose(stdin);fclose(stdout);
}

