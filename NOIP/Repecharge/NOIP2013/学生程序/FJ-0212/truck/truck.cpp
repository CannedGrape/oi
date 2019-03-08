#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <deque>

using namespace std;

#define MAXN 10050
#define MAXM 100050
#define MAX(a, b) ( (a) > (b) ? (a) : (b) )
#define ADDEDGE(s, d, w) do { \
	edges[ptr][0] = d; \
	edges[ptr][1] = w; \
	edges[ptr][2] = head[s]; \
	head[s] = ptr++; \
} while(0)

int head[MAXN];
int edges[MAXM][3];
int ptr = 1;
deque<int> q;
bool visited[MAXN];
int cmax = 0;

bool check(int s, int d, int mid)
{
	int curr, tmp;
	
	memset(visited, 0, sizeof(visited));
	q.clear();
	while (!q.empty())
		q.pop_back();
	q.push_back(s);	
	visited[s] = true;
	
	while (!q.empty())
	{
		curr = q.front();
		q.pop_front();
		tmp = head[curr];
		
		while (tmp)
		{
			if (!visited[edges[tmp][0]] && edges[tmp][1] >= mid)
			{
				visited[edges[tmp][0]] = true;
				q.push_back(edges[tmp][0]);
				if (edges[tmp][0] == d)
				{
					q.clear();
					return true;
				}
			}			
			tmp = edges[tmp][2];
		}
	}
	return false;
}

int getAns(int s, int d)
{
	int l = 0, r = cmax;
	int mid;
	
	if (!check(s, d, 0))
		return -1;
	
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (check(s, d, mid))
		{
			if (!check(s, d, mid + 1))
				return mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}	
	return l;
}

int main() {	
	int n, m;
	int a, b, c;
	int q;
	
	freopen("truck.in", "r", stdin);
	freopen("truck.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		ADDEDGE(a, b, c);
		ADDEDGE(b, a, c);
		cmax = MAX(c, cmax);
	}
	
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", getAns(a, b));
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
