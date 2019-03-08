#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int HASH_MOD = 5049677;
const int HASH_POW[5] = {0, 17, 289, 4913, 83521};
const int maxn = 30 + 5;
const int maxquelen = 131072;
const char dx[4] = {0, 1, 0, -1};
const char dy[4] = {1, 0, -1, 0};

int n, m, q;

struct Pos
{
	int x, y;
};
struct State
{
	Pos black, target;
};
inline bool isNearby(Pos a, Pos b)
{
	return a.x == b.x ? (a.y == b.y + 1 || a.y == b.y - 1) : (a.y == b.y && (a.x == b.x + 1 || a.x == b.x - 1));
}
inline bool operator==(Pos a, Pos b)
{
	return a.x == b.x && a.y == b.y;
}

int Grid[maxn][maxn] = {0};
inline bool isLegal(Pos a)
{
	return Grid[a.x][a.y] && (a.x > 0 && a.y > 0 && a.x <= n && a.y <= m);
}

State que[maxquelen];
int step[maxquelen];

int isexist[HASH_MOD] = {0};
inline int hash(State s)
{
	return (s.black.x * HASH_POW[1] + s.black.y * HASH_POW[2] + s.target.x * HASH_POW[3] + s.target.y * HASH_POW[4]) % HASH_MOD;
}
bool isExist(State s)
{
	return isexist[hash(s)];
}
void Reach(State s)
{
	isexist[hash(s)] = true;
}

State S;
Pos anspos;

State bfs_cache;

void BFS()
{
	int head = 0, tail = 0;
	que[0] = S;
	Reach(S);
	step[0] = 0;
	if (S.target == anspos)
	{
		puts("0");
		return ;
	}
	while (head != tail + 1 & maxquelen - 1)
	{
		if (isNearby(que[head].black, que[head].target))
		{
			bfs_cache.target = que[head].black;
			bfs_cache.black = que[head].target;
			if (!isExist(bfs_cache))
			{
				Reach(bfs_cache);
				que[tail = tail + 1 & maxquelen - 1] = bfs_cache;
				step[tail] = step[head] + 1;
				if (que[tail].target == anspos)
				{
					printf("%d\n", step[tail]);
					return ;
				}
			}
		}
		Pos u = que[head].black;
		bfs_cache.target = que[head].target;
		for (int i = 0; i < 4; i++)
		{
			Pos v;
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];
			if (isLegal(v) && !(v == bfs_cache.target))
			{
				bfs_cache.black = v;
				if (!isExist(bfs_cache))
				{
					Reach(bfs_cache);
					que[tail = tail + 1 & maxquelen - 1] = bfs_cache;
					step[tail] = step[head] + 1;
				}
			}
		}
		head = head + 1 & maxquelen - 1;
	}
	puts("-1");
}

int main()
{
	freopen("puzzle.in", "r", stdin);
	freopen("puzzle.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int ch;
			scanf("%d", &ch);
			if (ch)
			{
				Grid[i][j] = 1;
			}
		}
	}
	while (q--)
	{
		scanf("%d%d%d%d%d%d", &S.black.x, &S.black.y, &S.target.x, &S.target.y, &anspos.x, &anspos.y);
		BFS();
		memset(isexist, 0, sizeof(isexist));
	}
}
