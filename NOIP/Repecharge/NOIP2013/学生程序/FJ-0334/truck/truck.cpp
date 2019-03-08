#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
using std::min;

int don[1000][1000];

const int N = 10010, M = 50010, INF = 0x7F7F7F7F;
int EC, n, m, q;
struct Edge {
	int v, w;
	Edge *next;
} ES[M<<1], *header[N];
inline void AddEdge(const int a, const int b, const int c)
{
	ES[++EC].next = header[a];
	header[a] = ES + EC;
	header[a]->v = b;
	header[a]->w = c;
	ES[++EC].next = header[b];
	header[b] = ES + EC;
	header[b]->v = a;
	header[b]->w = c;
}
bool vis[N];
int dist[N];
struct Pair {
	int dist, v;
	Pair(const int a, const int b):
		dist(a), v(b) { }
};
inline bool operator<(const Pair &lhs, const Pair &rhs) { return lhs.dist < rhs.dist; }
inline int Dijkstra(const int x, const int y)
{
	memset(vis, 0, sizeof(vis));
	memset(dist, -1, sizeof(dist));
	std::priority_queue<Pair> Q;
	for (Q.push(Pair(dist[x] = INF, x)); !Q.empty(); ) {
		const Pair u = Q.top();
		Q.pop();
		if (u.dist != dist[u.v]) continue;
		vis[u.v] = true;
		for (Edge *e = header[u.v]; e; e = e->next)
			if (!vis[e->v] && min(dist[u.v], e->w) > dist[e->v])
				Q.push(Pair(dist[e->v] = min(dist[u.v], e->w), e->v));
	}
	return dist[y];
}
int main()
{
	freopen("truck.in", "r", stdin);
	freopen("truck.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1, x, y, z; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		AddEdge(x, y, z);
	}
	scanf("%d", &q);
	memset(don, -1, sizeof(don));
	for (int i = 1, x, y; i <= q; ++i) {
		scanf("%d%d", &x, &y);
		if (x < 1000 && y < 1000) {
			if (don[x][y] != -1) printf("%d\n", don[x][y]);
			else printf("%d\n", don[x][y] = don[y][x] = Dijkstra(x, y));
		} else printf("%d\n", Dijkstra(x, y));
	}
}
