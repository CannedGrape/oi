#include <stdio.h>
long long n, m, k, x;

long long pow(long long a, long long b) {
	long long hehe;
	if (b == 0) return 1;
	if (b == 1) return a;
	hehe = pow(a, b / 2);
	if (a % 2 == 1) return (hehe * hehe * a) % n;
	else return (hehe * hehe) % n;
}

int main() {
	long long ans;
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	scanf("%lld%lld%lld%lld", &n, &m, &k, &x);
	ans = pow(10, k);
	ans = (ans * m) % n;
	ans = (ans + x) % n;
	printf("%lld\n", ans);
	return 0;	
}
