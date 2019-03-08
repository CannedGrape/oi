/*
 * Problem:	Match
 * Source:	NOIP 2013 Day 1
 * Author:	Jason Lau<i@dotkrnl.com>
 * Licence:	MIT
 */
#include <cstdio>
#include <algorithm>

using namespace std;

#define PROB	"match"

void process(void);

int main(void) {
	freopen(PROB".in", "r", stdin);
	freopen(PROB".out", "w", stdout);
	process();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

const int MAXN = 110000;
const int MODER = 99999997;

struct match {
	int val, loc;
	bool operator < (const match &ot) const {
		return val < ot.val;
	}
	bool operator > (const match &ot) const {
		return val > ot.val;
	}
} A[MAXN+1], B[MAXN+1];

int C[MAXN+1];
int reverseCount(int l, int r);

void process(void) {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &(A[i].val)), A[i].loc = i;
	for (int i = 1; i <= n; i++)
		scanf("%d", &(B[i].val)), B[i].loc = i;
	sort(A + 1, A + n + 1);
	sort(B + 1, B + n + 1);
	for (int i = 1; i <= n; i++)
		C[A[i].loc] = B[i].loc;
	printf("%d\n", reverseCount(1, n));
}

int tmp[MAXN+1];

int reverseCount(int l, int r) {
	if (l == r) {
		tmp[l] = C[l]; return 0;
	}
	int mid = (l + r) >> 1;
	int ret = reverseCount(l, mid);
	ret += reverseCount(mid + 1, r);
	ret %= MODER;
	// then merge two part
	int begL = l, begR = mid+1;
	int endL = mid, endR = r;
	int currentLoc = l;
	while (begL <= endL && begR <= endR) {
		if (tmp[begR] < tmp[begL]) {
			C[currentLoc++] = tmp[begR++];
			ret += endL - begL + 1;
			while (ret >= MODER) ret -= MODER;
		} else C[currentLoc++] = tmp[begL++];
	}
	while (begL <= endL) C[currentLoc++] = tmp[begL++];
	while (begR <= endR) C[currentLoc++] = tmp[begR++];
	for (int i = l; i <= r; i++) tmp[i] = C[i];
	return ret % MODER;
}
