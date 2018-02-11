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

const int maxn = 100005;

struct line
{
	int l, r, h;
}r[maxn];

int fa[maxn], h[maxn], t[maxn], n, tot;

bool cmp(int a, int b)
{
	return h[a] > h[b];
}

void merge(int u, int v)
{
	--tot;
	fa[u] = v;
	r[v].l = min(r[u].l, r[v].l);
	r[v].r = max(r[u].r, r[v].r);
}

int getfa(int now)
{
	return fa[now] == -1 ? now : fa[now] = getfa(fa[now]);
}

int main()
{
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &h[i]);
		
	int tn = 1;
	for (int i = 1; i < n; ++i)
		if (h[i] != h[tn - 1])
			h[tn++] = h[i];
	tot = n = tn;
	
	for (int i = 0; i < n; ++i)
		r[i].l = r[i].r = i, r[i].h = h[i], t[i] = i, fa[i] = -1;
	sort(t, t + n, cmp);
	
	if (n == 1) printf("%d", h[0]);
	else
	{
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int now = getfa(t[i]);
			if (r[now].h != h[t[i]]) continue;
			
			int mx = 0;
			if (r[now].l > 0)
				mx = max(mx, r[getfa(r[now].l - 1)].h);
			if (r[now].r < n - 1)
				mx = max(mx, r[getfa(r[now].r + 1)].h);
			ans += r[now].h - mx;
			r[now].h = mx;
			
			if (r[now].l > 0 && r[getfa(r[now].l - 1)].h == mx)
				merge(now, getfa(r[now].l - 1));
			now = getfa(now);
			
			if (r[now].r < n - 1 && r[getfa(r[now].r + 1)].h == mx)
				merge(now, getfa(r[now].r + 1));
			now = getfa(now);
			
			if (tot == 1) 
			{
				ans += r[now].h;
				break;
			}
		}
		printf("%d", ans);
	}
	fclose(stdin);fclose(stdout);
}


