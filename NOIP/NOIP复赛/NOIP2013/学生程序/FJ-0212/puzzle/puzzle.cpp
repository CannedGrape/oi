#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <deque>

using namespace std;

#define MAXN 35
#define NEXTX (curr.ex + dir[i][0])
#define NEXTY (curr.ey + dir[i][1])

struct GameStatus
{
	int ex, ey;
	int sx, sy;
	int step;
};

int status[MAXN][MAXN];
bool visited[MAXN][MAXN];
deque<GameStatus> q;
const int dir[4][2] = { { -1 , 0}, { 1, 0}, { 0, -1}, { 0, 1} };

// use  & cout only~!!!!!!!!!

int search(int ex, int ey, int sx, int sy, int dx, int dy)
{
	GameStatus tmp, curr;
	
	memset(visited, 0, sizeof(visited));
	q.clear();
	while (!q.empty())
	   q.pop_back();
	
	visited[ex][ey] = true;
	tmp.ex = ex;
	tmp.ey = ey;
	tmp.sx = sx;
	tmp.sy = sy;
	tmp.step = 0;
	q.push_back(tmp);
	
	while (!q.empty())
	{
		curr = q.front();
		q.pop_front();
		
		if (curr.sx == dx && curr.sy == dy)
			return curr.step;
		
		for (int i=0; i<4; i++)
		{
			if (status[NEXTX][NEXTY] == 1 && !visited[NEXTX][NEXTY])
			{
				visited[NEXTX][NEXTY] = true;
				tmp.ex = NEXTX;
				tmp.ey = NEXTY;
				tmp.step = curr.step + 1;
				if (NEXTX == curr.sx && NEXTY == curr.sy)
				{
					tmp.sx = curr.ex;
					tmp.sy = curr.ey;
				} else
				{
					tmp.sx = curr.sx;
					tmp.sy = curr.sy;
				}
				q.push_back(tmp);
			}
		}
	}
	return -1;
}

int main() {
	int n, m, q;
	int a, b, c, d, e, f;	
	
	freopen("puzzle.in", "r", stdin);
	freopen("puzzle.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d", &status[i][j]);
	
	for (int i=1; i<=q; i++)
	{
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		printf("%d\n", search(a, b, c, d, e, f));
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
