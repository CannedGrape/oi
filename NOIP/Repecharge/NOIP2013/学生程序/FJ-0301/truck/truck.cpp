#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 10001, MAXM = 50000, MAXD = 16;
struct Edge
{
  int v, w;
  Edge *next;
} g[MAXN*2], *header[MAXN];
void AddEdge(const int x, const int y, const int w)
{
  static int LinkSize;
  Edge* const node = g+(LinkSize++);
  node->v = y;
  node->w = w;
  node->next = header[x];
  header[x] = node;
}
struct Road { int x, y, w; };
inline bool operator<(const Road& lhs, const Road& rhs) { return lhs.w > rhs.w; }
Road road[MAXM];
int n, m, q, un[MAXN], p[MAXN][MAXD], d[MAXN], w[MAXN][MAXD];
int getparent(const int u)
{
  if (un[u] == u) return u;
  return un[u] = getparent(un[u]);
}
void build(const int source)
{
  std::queue<int> Q;
  for (Q.push(source), p[source][0] = source, d[source] = 1; !Q.empty(); Q.pop())
  {
    const int u = Q.front();
    for (int j = 1; j < MAXD; ++j)
    {
      p[u][j] = p[p[u][j-1]][j-1];
      w[u][j] = std::min(w[u][j-1], w[p[u][j-1]][j-1]);
    }
    for (Edge *e = header[u]; e; e = e->next)
    {
      if (e->v == p[u][0]) continue;
      p[e->v][0] = u;
      w[e->v][0] = e->w;
      d[e->v] = d[u]+1;
      Q.push(e->v);
    }
  }
}
int get(int u, int v)
{
  int res = 0x7FFFFFFF;
  if (d[u] < d[v]) std::swap(u, v);
  for (int k; d[u] != d[v]; u = p[u][k-1])
  {
    for (k = 1; d[p[u][k]] > d[v]; ++k);
    res = std::min(res, w[u][k-1]);
  }
  for (int k; u != v; u = p[u][k-1], v = p[v][k-1])
  {
    for (k = 1; p[u][k] != p[v][k]; ++k);
    res = std::min(res, std::min(w[u][k-1], w[v][k-1]));
  }
  return res;
}
int main()
{
  freopen("truck.in", "r", stdin);
  freopen("truck.out", "w", stdout);
  
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i)
    scanf("%d%d%d", &road[i].x, &road[i].y, &road[i].w);
  std::sort(road, road+m);
  for (int i = 1; i <= n; ++i) un[i] = i;
  for (int i = 0; i < m; ++i)
  {
    const int pa = getparent(road[i].x);
    const int pb = getparent(road[i].y);
    if (pa != pb)
    {
      un[pa] = pb;
      AddEdge(road[i].x, road[i].y, road[i].w);
      AddEdge(road[i].y, road[i].x, road[i].w);
    }
  }
  for (int i = 1; i <= n; ++i)
    if (p[i][0] == 0)
      build(i);
  scanf("%d", &q);
  for (int x, y; q--; )
  {
    scanf("%d%d", &x, &y);
    const int pa = getparent(x), pb = getparent(y);
    printf("%d\n", pa == pb ? get(x, y) : -1);
  }
  
  fclose(stdin);fclose(stdout);
}
