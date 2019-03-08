#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
typedef long long ll;

struct point
{
	int x, y;
	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

point operator+(point a, point b) 
{ 
	return point(a.x + b.x, a.y + b.y);
}

bool operator==(point a, point b)
{
	return a.x == b.x && a.y == b.y;
}

struct member
{
	point a;
	int d;
	member(point _a = point(0, 0), int _d = 0) : a(_a), d(_d) {}
};

queue<member> q;
queue<point> q2;

const point d[4] = {point(-1, 0), point(0, 1), point(0, -1), point(1, 0)};

int dist[32][32][4][4], n, m, Q, b[32][32][4], p[32][32], di[32][32], di2[32][32][4], ans;
point e, s, t;

bool check(point a)
{
	if (a.x < 1 || a.x > n || a.y < 1 || a.y > m || p[a.x][a.y] == 0) return false;
	else return true;
}

void pre_bfs(point no, int z)
{
	if (!check(no + d[z])) return;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			di[i][j] = -1;
	di[(no + d[z]).x][(no + d[z]).y] = 0;
	q2.push(no + d[z]);
	
	while (!q2.empty())
	{
		point now = q2.front();
		int dis = di[now.x][now.y];
		q2.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			point to = now + d[i];
			if (!check(to) || to == no || di[to.x][to.y] != -1) continue;
			di[to.x][to.y] = dis + 1;
			q2.push(to);
		}
	}
	
	for (int i = 0; i < 4; ++i)
		if (check(no + d[i]))
			dist[no.x][no.y][z][i] = di[(no + d[i]).x][(no + d[i]).y];
		else dist[no.x][no.y][z][i] = -1;
}

void pre_bfs2(point no, point wtf)
{	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			di[i][j] = -1;
			for (int k = 0; k < 4; ++k)
				di2[i][j][k] = -1;
		}
	di[no.x][no.y] = 0;
	q2.push(no);
	
	while (!q2.empty())
	{
		point now = q2.front();
		int dis = di[now.x][now.y];
		q2.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			point to = now + d[i];
			if (!check(to) || to == wtf || di[to.x][to.y] != -1) continue;
			di[to.x][to.y] = dis + 1;
			q2.push(to);
		}
	}
	
	for (int i = 0; i < 4; ++i)
	{
		point to = wtf + d[i];
		int dis = di[to.x][to.y];
		if (!check(to) || dis == -1) continue;
		q.push(member(wtf, i));
		di2[wtf.x][wtf.y][i] = dis;
		b[wtf.x][wtf.y][i] = 1;
	}
}

void bfs()
{
	while (!q.empty())
	{
		member now = q.front();
		q.pop();
		point nowp = now.a;
		int dic = now.d, dis = di2[nowp.x][nowp.y][dic];
		if (nowp == t) ans = min(ans, dis);
		
		for (int i = 0; i < 4; ++i)
		{
			point to = nowp + d[i];
			if (!check(to) || dist[nowp.x][nowp.y][dic][i] == -1) continue;
			if (di2[to.x][to.y][3 - i] != -1 && 
					di2[to.x][to.y][3 - i] <= dis + dist[nowp.x][nowp.y][dic][i] + 1) continue;
			di2[to.x][to.y][3 - i] = dis + dist[nowp.x][nowp.y][dic][i] + 1;
			if (!b[to.x][to.y][3 - i])
			{
				b[to.x][to.y][3 - i] = 1;
				q.push(member(to, 3 - i));
			}
		}
		b[nowp.x][nowp.y][dic] = 0;
	}
}

int main()
{
	freopen("puzzle.in", "r", stdin);
	freopen("puzzle.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &Q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &p[i][j]);
			for (int k = 0; k < 4; ++k)
				for (int l = 0; l < 4; ++l)
					dist[i][j][k][l] = -1;
		}
			
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (check(point(i, j)))
				for (int k = 0; k < 4; ++k)
					pre_bfs(point(i, j), k);
	
	for (int i = 0; i < Q; ++i)
	{
		scanf("%d%d%d%d%d%d", &e.x, &e.y, &s.x, &s.y, &t.x, &t.y);
		if (s == t)
		{
			printf("0\n");
			continue;
		}
		if (!check(e) || !check(s) || !check(t))
		{
			printf("-1\n");
			continue;
		}
		ans = 0x7fffffff;
		memset(b, 0, sizeof(b));
		pre_bfs2(e, s);
		bfs();
		printf("%d\n", ans == 0x7fffffff ? -1 : ans);
	}
	fclose(stdin);fclose(stdout);
}

