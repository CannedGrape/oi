#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
const int N = 32, INF = 0x7F7F7F7F;
const int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, q, a[N][N], ex, ey, sx, sy, tx, ty, ans;
inline int abs(const int x) { return x<0?-x:x; }
struct Info {
	int ex, ey, sx, sy, cost;
	Info(const int a, const int b, const int c, const int d, const int e):
		ex(a), ey(b), sx(c), sy(d), cost(e) { }
};
/*
struct Hash {
	int ex, ey, sx, sy;
	Hash(const int a, const int b, const int c, const int d):
		ex(a), ey(b), sx(c), sy(d) { }
};
std::map<Hash, bool> Hs;
inline bool operator<(const Hash &a, const Hash &b)
{
	return (a.ex < b.ex) || (a.ex == b.ex && a.ey < b.ey) || (a.ex == b.ex && a.ey == b.ey && a.sx < b.sx) || (a.ex == b.ex && a.ey == b.ey && a.sx == b.sx && a.sy < b.sy);
}*/
bool Hs[31][31][31][31];
inline void BFS()
{
	std::queue<Info> Q;
	for (Q.push(Info(ex, ey, sx, sy, 0)); !Q.empty(); ) {
		Info c = Q.front();
		Q.pop();
		if (Hs[c.ex][c.ey][c.sx][c.sy]) continue;
		Hs[c.ex][c.ey][c.sx][c.sy] = true;
		if (c.cost > ans) continue; 
		if ((c.cost + abs(c.sx - tx) + abs(c.sy - ty)) > ans) continue;
		if (c.sx == tx && c.sy == ty) {
			if (c.cost < ans) ans = c.cost;
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int xx = c.ex + move[i][0], yy = c.ey + move[i][1];
			if (1<=xx&&xx<=n && 1<=yy&&yy<=m && a[xx][yy]==1) {
				if (xx == c.sx && yy == c.sy)
					Q.push(Info(xx, yy, c.ex, c.ey, c.cost+1));
				else
					Q.push(Info(xx, yy, c.sx, c.sy, c.cost+1));
			}
		}
	}
}
inline void Init()
{
	ans = INF;
//	Hs.clear();
	memset(Hs, 0, sizeof(Hs));
}
int main()
{
	freopen("puzzle.in", "r", stdin);
	freopen("puzzle.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);
		Init();
		BFS();
		if (ans == INF) puts("-1"); else printf("%d\n", ans);
	}
}
