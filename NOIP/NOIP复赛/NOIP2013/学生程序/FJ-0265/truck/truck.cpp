#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
typedef long long ll;

const int maxn = 10005;
const int maxm = 1000005;

struct lin
{
	int fr, to, v;
}t[maxm];

struct line
{
	int to, next, v;
}li[maxm];

int be[maxn], n, m, Q, fa[maxn], fat[maxn][22][2], l, b[maxn], d[maxn];
queue<int> q;

void makeline(int fr, int to, int v)
{
	++l;
	li[l].next = be[fr];
	be[fr] = l;
	li[l].to = to;
	li[l].v = v;
}

bool cmp(lin a, lin b)
{
	return a.v > b.v;
}

int getfa(int now)
{
	return fa[now] == 0 ? now : fa[now] = getfa(fa[now]);
}

bool check(int now)
{
	return now >= 1 && now <= n;
}

void bfs(int no)
{
	b[no] = d[no] = 1;
	q.push(no);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		for (int i = 1, k = fat[now][0][0]; fat[k][i - 1][0]; k = fat[k][i - 1][0], ++i)
			fat[now][i][0] = fat[k][i - 1][0],
			fat[now][i][1] = min(fat[now][i - 1][1], fat[k][i - 1][1]);
		
		for (int i = be[now]; i; i = li[i].next)
		{
			int to = li[i].to;
			if (to == fat[now][0][0]) continue;
			fat[to][0][0] = now;
			fat[to][0][1] = li[i].v;
			d[to] = d[now] + 1;
			b[to] = 1;
			q.push(to);			
		}
	}
}

int query(int u, int v)
{
	if (d[u] < d[v]) swap(u, v);
	int i, ans = 0x7fffffff;
	
	while (d[u] > d[v])
	{
		for (i = 20; i >= 0; --i)
			if (d[u] - (1 << i) >= d[v])
				break;
		if (i == -1) i = 0;
		ans = min(ans, fat[u][i][1]);
		u = fat[u][i][0];
	}
	
	while (u != v)
	{
		for (i = 20; i >= 0; --i)
			if (fat[u][i][0] != fat[v][i][0])
				break;
		if (i == -1) i = 0;
		ans = min(ans, min(fat[u][i][1], fat[v][i][1]));
		u = fat[u][i][0];
		v = fat[v][i][0];
	}
	return ans;
}

int main()
{
	freopen("truck.in", "r", stdin);
	freopen("truck.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d%d%d", &t[i].fr, &t[i].to, &t[i].v);		
	
	sort(t, t + m, cmp);
	for (int i = 0; i < m; ++i)
		if (getfa(t[i].fr) != getfa(t[i].to))
		{
			fa[getfa(t[i].fr)] = getfa(t[i].to);
			makeline(t[i].fr, t[i].to, t[i].v);
			makeline(t[i].to, t[i].fr, t[i].v);
		}
	
	for (int i = 1; i <= n; ++i)
		if (!b[i])
			bfs(i);
	
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i)
	{
		int fr, to;
		scanf("%d%d", &fr, &to);
		if (!check(fr) || !check(to) || getfa(fr) != getfa(to))
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n", query(fr, to));
	}
	fclose(stdin);fclose(stdout);
}


