/*
 * Problem:	Flower
 * Author:	Jason Lau<i@dotkrnl.com>
 * Source:	NOIP 2013 Day 2
 * Licence:	MIT
 */
#include <cstdio>

#define PROB	"flower"

using namespace std;

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
const int MAXHEIGHT = 1010000 + 2; // plus 2 for 0 supporting
const int CUTN = 1100;

int value[MAXN+1];

int dp(int n);

void process(void) {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &value[i]);
	printf("%d\n", dp(n));
}

int maxbefore(int queue, int height);
void addqueue(int queue, int height, int ans);

int dp(int n) {
	static int f[MAXN+1][2];
	int maxans = 0;
	// 0 stands for last high2low
	// 1 stands for last low2high
	for (int i = 1; i <= n; i++) {
		f[i][0] = 1; f[i][1] = 1;
		if (n <= CUTN) {
			for (int j = 1; j < i; j++)
				if (value[j] > value[i]) {
					int cur = f[j][1] + 1;
					if (cur > f[i][0]) f[i][0] = cur;
				} else if (value[j] < value[i]) {
					int cur = f[j][0] + 1;
					if (cur > f[i][1]) f[i][1] = cur;
				}
		} else {
			int get4zero = maxbefore(1, value[i]) + 1;
			int get4one = maxbefore(0, value[i]) + 1;
			if (get4zero > 1) f[i][0] = get4zero;
			if (get4one > 1) f[i][1] = get4one;
			addqueue(0, value[i], f[i][0]);
			addqueue(1, value[i], f[i][1]);
		}
		if (f[i][0] > maxans) maxans = f[i][0];
		if (f[i][1] > maxans) maxans = f[i][1];
	}
	return maxans;
}

int segtree[MAXHEIGHT + 2][2];

inline int lowbit(int a) {
	return int(unsigned(a) & unsigned(-a));
}

int maxbefore(int queue, int height) {
	int maxv = 0; height++; // height 0 not supported so shift 1
	if (queue == 1) height = MAXHEIGHT - height;
	height--; if (!height) return 0; // for before supporting
	for (; height; height -= lowbit(height))
		if (segtree[height][queue] > maxv) maxv = segtree[height][queue];
	return maxv;
}

void addqueue(int queue, int height, int ans) {
	height++; // height 0 not supported so shift 1
	if (queue == 1) height = MAXHEIGHT - height;
	for (; height <= MAXHEIGHT; height += lowbit(height))
		if (segtree[height][queue] < ans) segtree[height][queue] = ans;
}
