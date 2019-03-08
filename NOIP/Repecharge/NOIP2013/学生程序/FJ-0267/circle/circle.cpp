/*
 * Problem:	Circle
 * Source:	NOIP 2013 Day 1
 * Author:	Jason Lau<i@dotkrnl.com>
 * Licence:	MIT
 */
#include <cstdio>

using namespace std;

#define PROB	"circle"

void process(void);

int main(void) {
	freopen(PROB".in", "r", stdin);
	freopen(PROB".out", "w", stdout);
	process();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

typedef unsigned long long ull;

int moder;
int qpow(int base, int pow);

void process(void) {
	int n, m, k, x;
	scanf("%d%d%d%d", &n, &m, &k, &x);
	moder = n;
	int ans = qpow(10, k) % n;
	ans = int((ull(ans) * ull(m)) % ull(n));
	ans = int((ull(ans) + ull(x)) % ull(n));
	printf("%d\n", ans % n);
}

int qpow(int base, int pow) {
	if (pow == 0) return 1;
	else {
		int get = qpow(base, pow >> 1);
		int ret = int((ull(get) * ull(get)) % ull(moder));
		if (pow & 1) ret = int((ull(ret) * ull(base)) % ull(moder));
		return ret;
	}
}
