/*
 * Problem:	Block
 * Author:	Jason Lau<i@dotkrnl.com>
 * Source:	NOIP 2013 Day 2
 * Licence:	MIT
 */
#include <cstdio>

#define PROB	"block"

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

int value[MAXN + 1];

void process(void) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &value[i]);
	value[n] = 0;
	for (int i = n; i >= 1; i--)
		value[i] -= value[i-1];
	int answer = 0;
	for (int i = 0; i <= n; i++)
		if (value[i] > 0) answer += value[i];
	printf("%d\n", answer);
}
