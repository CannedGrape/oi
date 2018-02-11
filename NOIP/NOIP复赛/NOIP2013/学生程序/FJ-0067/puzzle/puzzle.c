#include <stdio.h>
#include <string.h>
#define MOD 250597
int n, m, qu, map[40][40], vis[31][31][31][31], ex, ey, sx, sy, tx, ty, dis[5000000];
int q[5000000][2], head, rear;
int dir[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};

int bfs1() {
	int i, x, y, dx, dy;
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	head = rear = 0;
	q[rear][0] = ex * m + ey;
	q[rear][1] = sx * m + sy;
	rear++;
	vis[ex][ey][sx][sy] = 1;
	while (head < rear) {
		//printf("%d %d\n", head, q[head][0]);
		x = q[head][0] / m;
		y = q[head][0] % m;
		sx = q[head][1] / m;
		sy = q[head][1] % m;
		if (sx == tx && sy == ty) {
			return dis[head];
		}
		//printf("%d %d\n", x, y);
		for (i = 0; i < 4; i++) {
			dx = dir[i][0] + x;
			dy = dir[i][1] + y;
			if (dx == sx && dy == sy) {
				//printf("	hehe\n");
				if (!vis[sx][sy][x][y]) {
					vis[sx][sy][x][y] = 1;
					q[rear][0] = dx * m + dy;
					q[rear][1] = x * m + y;
					dis[rear] = dis[head] + 1;
					//printf("	%d %d %d\n", q[rear2][0], q[rear2][1], dis[rear2]);
					rear++;
				}
			}
			else if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && map[dx][dy] && !vis[dx][dy][sx][sy]) {
				q[rear][0] = dx * m + dy;
				q[rear][1] = q[head][1];
				vis[dx][dy][sx][sy] = 1;
				dis[rear] = dis[head] + 1;
				rear++;
			}
		}
		head++;	
	}
	return -1;
}

int main() {
	int i, j;
	freopen("puzzle.in", "r", stdin);
	freopen("puzzle.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &qu);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);	
		}
	}
	while (qu--) {
		scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);
		//printf("%d %d %d %d %d %d %d\n", ex, ey, sx, sy, tx, ty, m);
		printf("%d\n", bfs1());
	}
	return 0;	
}
