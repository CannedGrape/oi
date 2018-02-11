/*
 * Problem:	Truck
 * Source:	NOIP 2013 Day 1
 * Author:	Jason Lau<i@dotkrnl.com>
 * Licence:	MIT
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define PROB	"truck"

void process(void);

int main(void) {
	freopen(PROB".in", "r", stdin);
	freopen(PROB".out", "w", stdout);
	process();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

const int MAXN = 11000;
const int MAXM = 51000;
const int MAXJUMP = 16;
const int INF = 0x3FFFFFFF;

struct edge {
	int x, y, z;
	bool operator <(const edge &ot) const {
		return z < ot.z;
	}
	bool operator >(const edge &ot) const {
		return z > ot.z;
	}
} input[MAXM + 1];

struct link {
	int to, dist;
	link *next;
	link(int t, int d, link *n)
		: to(t), dist(d), next(n) {}
} *tree[MAXN + 1];

void merge(int i, int j);
int getFather(int a);
int size[MAXN + 1], father[MAXN + 1];

void bfsGenTree(int n);
int getMinDist(int i, int j);

void process(void) {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &(input[i].x),
				&(input[i].y), &(input[i].z));
	for (int i = 1; i <= n; i++) size[i] = 1;
	sort(input + 1, input + m + 1);
	for (int i = m; i >= 1; i--) {
		int fatherX = getFather(input[i].x),
			fatherY = getFather(input[i].y);
		if (fatherX == fatherY) continue;
		merge(fatherX, fatherY);
		tree[input[i].x] = new link(input[i].y, input[i].z, tree[input[i].x]);
		tree[input[i].y] = new link(input[i].x, input[i].z, tree[input[i].y]);
	}
	bfsGenTree(n);
	int q; scanf("%d", &q);
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		int fatherX = getFather(x),
			fatherY = getFather(y);
		if (fatherX != fatherY) printf("-1\n");
		else printf("%d\n", getMinDist(x, y));
	}
}

void merge(int i, int j) { // i, j should be root
	if (size[i] >= size[j]) {
		father[j] = i;
		size[i] += size[j];
	} else {
		father[i] = j;
		size[j] += size[i];
	}
}

int getFather(int a) {
	static int stack[MAXN+1];
	int end = 0;
	while (father[a]) {
		stack[end++] = a;
		a = father[a];
	}
	for (int i = 0; i < end; i++)
		father[stack[i]] = a;
	return a;
}

bool visited[MAXN + 1];
int jumpNodeID[MAXN + 1][MAXJUMP];
int jumpMinDist[MAXN + 1][MAXJUMP];
int depth[MAXN + 1];

void genOneTree(int root);
void bfsGenTree(int n) {
	for (int i = 1; i <= n; i++)
		if (!visited[i]) genOneTree(i);
}

void genOneTree(int root) {
	static int queue[MAXN+1];
	int head = 0, tail = 1;
	queue[head] = root; visited[root] = true; depth[root] = 0;
	jumpNodeID[root][0] = root; jumpMinDist[root][0] = INF;
	for (; head != tail; head++) {
		int cur = queue[head];
		for (link *i = tree[cur]; i; i = i->next) {
			if (visited[i->to]) continue;
			queue[tail++] = i->to; visited[i->to] = true;
			depth[i->to] = depth[cur] + 1;
			jumpNodeID[i->to][0] = cur; jumpMinDist[i->to][0] = i->dist;
		}
	}
	for (int i = 1; i < MAXJUMP; i++)
		for (int head = 0; head < tail; head++) {
			int cur = queue[head];
			int jumpTO = jumpNodeID[cur][i-1];
			jumpNodeID[cur][i] = jumpNodeID[jumpTO][i-1];
			jumpMinDist[cur][i] = min(
				jumpMinDist[cur][i-1],
				jumpMinDist[jumpTO][i-1]
			);
		}
}

inline int jumpLoc(int i, int diffDepth, int *ans = NULL) {
	for (int jmp = MAXJUMP - 1; jmp >= 0; jmp--)
		if (diffDepth >= (1 << jmp)) {
			diffDepth -= (1 << jmp);
			if (ans) *ans = min(*ans, jumpMinDist[i][jmp]);
			i = jumpNodeID[i][jmp];
		}
	return i;
}

inline bool check(int i, int j, int updepth) {
	int ji = jumpLoc(i, updepth, NULL),
		jj = jumpLoc(j, updepth, NULL);
	return ji == jj;
}

int getMinDist(int i, int j) {
	int ans = INF;
	if (depth[i] < depth[j]) swap(i, j);
	i = jumpLoc(i, depth[i] - depth[j], &ans);
	int l = 0, r = depth[i];
	while (l != r) {
		int mid = (l + r) >> 1;
		if (check(i, j, mid)) r = mid;
		else l = mid + 1;
	}
	i = jumpLoc(i, l, &ans);
	j = jumpLoc(j, l, &ans);
	return ans;
}
