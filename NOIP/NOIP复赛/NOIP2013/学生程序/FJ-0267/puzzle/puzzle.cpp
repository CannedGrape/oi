/*
 * Problem:	Puzzle
 * Author:	Jason Lau<i@dotkrnl.com>
 * Source:	NOIP 2013 Day 2
 * Licence:	MIT
 */
#include <cstdio>

#define PROB	"puzzle"

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

const int MAXN = 35;
const int MAXQUEUE = MAXN * MAXN * MAXN * MAXN;

int bfs(int n, int m); // from input

bool able[MAXN+1][MAXN+1];
void process(void) {
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int val; scanf("%d", &val);
			able[i][j] = (val != 0);
		}
	while (q--) printf("%d\n", bfs(n, m));
}	

const int mvx[] = {0, 0, 1, -1};
const int mvy[] = {1, -1, 0, 0};

inline bool check(int n, int m, int i, int j) {
	return i && j && (i <= n) && (j <= m) && able[i][j];
}

int bfs(int n, int m) {
	static int visited[MAXN+1][MAXN+1][MAXN+1][MAXN+1];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		for (int k = 1; k <= n; k++) for (int l = 1; l <= m; l++)
			visited[i][j][k][l] = 0;
	static int queueEX[MAXQUEUE + 1], queueEY[MAXQUEUE + 1];
	static int queueSX[MAXQUEUE + 1], queueSY[MAXQUEUE + 1];
	static int depth[MAXQUEUE + 1];
	int head = 0, tail = 1;
	int ex, ey, sx, sy, tx, ty;
	scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);
	if (sx == tx && sy == ty) return 0;
	if (!able[ex][ey] || !able[sx][sy] || !able[tx][ty]) return -1;
	queueEX[0] = ex; queueEY[0] = ey;
	queueSX[0] = sx; queueSY[0] = sy;
	depth[0] = 0; visited[ex][ey][sx][sy] = 1;
	for (; head != tail; head++) {
		int ex = queueEX[head], ey = queueEY[head],
			sx = queueSX[head], sy = queueSY[head];
		for (int i = 0; i < 4; i++) {
			int nex = ex + mvx[i], ney = ey + mvy[i];
			int nsx = sx, nsy = sy;
			if (nex == sx && ney == sy) { nsx = ex; nsy = ey; }
			if (check(n, m, nex, ney) && !visited[nex][ney][nsx][nsy]) {
				if (nsx == tx && nsy == ty) return depth[head] + 1;
				queueEX[tail] = nex; queueEY[tail] = ney;
				queueSX[tail] = nsx; queueSY[tail] = nsy;
				depth[tail++] = depth[head] + 1;
				visited[nex][ney][nsx][nsy] = 1;
			}
		}
	}
	return -1;
}
