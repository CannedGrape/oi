#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
typedef long long ll;
ll n,m,k,x;
ll Pow(ll a,ll b) {
	ll s = 1;
	while (b) {
		if (b & 1) s = s * a % n;
		b = b / 2;
		a = a * a % n;
	}
	return s;
}
int main() {
	freopen("circle.in","r",stdin); freopen("circle.out","w",stdout);
	std::cin >> n >> m >> k >> x;
	ll v = Pow(10,k);
	x = (x + v * m % n) % n;
	std::cout << x;
	fclose(stdin); fclose(stdout);
}
