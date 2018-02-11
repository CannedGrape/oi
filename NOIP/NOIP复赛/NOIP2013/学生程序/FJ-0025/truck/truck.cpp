#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

const int maxn = 10050, maxm = 100050,
			INF = 1000000;

int N, M, Q;
int to[maxm], weight[maxm],
	next[maxm] = {0}, head[maxn] = {0}, sz = 0;
int answer[3001][3001] = {{0}};
bool vis[maxn] = {false};
	
inline int max(int a, int b)
{
	return a > b ? a : b;
}

inline int min(int a, int b)
{
	return a < b ? a : b;
}

void ins(int u, int v, int w)
{
	sz++;
	to[sz] = v;
	weight[sz] = w;
	next[sz] = head[u];
	head[u] = sz;
}

void init()
{
	int x, y, w;
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; ++i)
	{
		scanf("%d%d%d", &x, &y, &w);
		ins(x, y, w);
		ins(y, x, w);
	}
}

int DFS(int now, int b, int minw = INF)
{
	if(now == b)
	{
		return minw;
	}
	int tt = -1;
	vis[now] = true;
	for(int i = head[now]; i; i = next[i])
	{
		if(!vis[to[i]])
		{
			vis[to[i]] = true;
			tt = max( tt,
					DFS( to[i], b, min( minw, weight[i] ) ) );
			vis[to[i]] = false;
		}
	}
	return tt;
}



int main()
{
    freopen("truck.in", "r", stdin);
    freopen("truck.out", "w", stdout);
    int x, y, t;
    init();
    scanf("%d", &Q);
    for(int i = 1; i <= Q; ++i)
    {
		scanf("%d%d", &x, &y);
		memset(vis, 0, sizeof(vis));
		if(x > y)
		{
			t = x;
			x = y;
			y = t;
		}
		if(answer[x][y])
			t = answer[x][y];
		else
		{
			if(x <= 3000 && y <= 3000)
				t = answer[x][y] = DFS(x, y);
			else
				t = DFS(x, y);
		}
		printf("%d\n", t);
	}
    

    return 0;
}
