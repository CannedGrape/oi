#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <functional>
#include <climits>

using namespace std;

const int maxn = 10000 + 50;
const int maxm = 50000 + 50;

inline int log2(int k)
{
	return int(log(double(k)) / log(2.0));
}

//================================================================================
//MST
//================================================================================
struct MST_E
{
	int u, v, w;
};
bool operator>(MST_E a, MST_E b)
{
	return a.w > b.w;
}
MST_E me[maxm];
int fa[maxn] = {0};
int GetFa(int x)
{
	if (fa[x] == 0)
	{
		return fa[x] = x;
	}
	return fa[x] == x ? x : fa[x] = GetFa(fa[x]);
}

void UnionSet(int x, int y)
{
	int Fx = GetFa(x);
	int Fy = GetFa(y);
	fa[Fx] = Fy;
}
//================================================================================
struct Edge
{
	int v, w, Pre;
	Edge(int _v = 0, int _w = 0, int _Pre = 0):v(_v), w(_w), Pre(_Pre){}
};

Edge E[maxm << 1];
int EN[maxn] = {0};
int lastedge = 1;
void InsEdge(int u, int v, int w)
{
	E[++lastedge] = Edge(v, w, EN[u]);
	EN[u] = lastedge;
	E[++lastedge] = Edge(u, w, EN[v]);
	EN[v] = lastedge;
}
int minw[maxn][16] = {0};
int anci[maxn][16] = {0};
int depth[maxn] = {0};

void DFS(int u, int fa)
{
	for (int i = EN[u]; i; i = E[i].Pre)
	{
		if (E[i].v != fa)
		{
			depth[E[i].v] = depth[u] + 1;
			minw[E[i].v][0] = E[i].w;
			anci[E[i].v][0] = u;
			for (int j = 1; j < 15; j++)
			{
				anci[E[i].v][j] = anci[anci[E[i].v][j - 1]][j - 1];
				minw[E[i].v][j] = min(minw[E[i].v][j - 1], minw[anci[E[i].v][j - 1]][j - 1]);
			}
			DFS(E[i].v, u);
		}
	}
}

int Query(int S, int T)
{
	int res = INT_MAX >> 5;
	if (depth[S] < depth[T])
		swap(S, T);
	int u = S, v = T;
	if (depth[u] > depth[v])
	{
		int det = depth[u] - depth[v];
		while (det)
		{
			int k = log2(det);
			res = min(res, minw[u][k]);
			u = anci[u][k];
			det -= 1 << k;
		}
	}
	if (u == v)
		return res;
	for (int i = 14; i > 0; i--)
	{
		if (anci[u][i] == anci[v][i] && (i || u == v))
			continue;
		res = min(res, minw[u][i]);
		res = min(res, minw[v][i]);
		u = anci[u][i];
		v = anci[v][i];
	}
	return res;
}
//================================================================================
int n, m, q;

int main()
{
	freopen("truck.in", "r", stdin);
	freopen("truck.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &me[i].u, &me[i].v, &me[i].w);
	}
	sort(me + 1, me + 1 + m, greater<MST_E>());
	for (int i = 1; i <= m; i++)
	{
		if (GetFa(me[i].u) != GetFa(me[i].v))
		{
			UnionSet(me[i].u, me[i].v);
			InsEdge(me[i].u, me[i].v, me[i].w);
		}
	}
	for (int i = 2; i <= n; i++)
	{
		int F1 = GetFa(1);
		int Fx = GetFa(i);
		if (Fx != F1)
		{
			UnionSet(F1, Fx);
			InsEdge(F1, Fx, -1);
		}
	}
	depth[1] = 1;
	for (int i = 0; i < 15; i++)
		minw[0][i] = minw[1][i] = INT_MAX >> 5, anci[0][i] = anci[1][i] = 0;
	DFS(1, 0);
	scanf("%d", &q);
	while (q--)
	{
		int S, T;
		scanf("%d%d", &S, &T);
		printf("%d\n", Query(S, T));
	}
	return 0;
}
