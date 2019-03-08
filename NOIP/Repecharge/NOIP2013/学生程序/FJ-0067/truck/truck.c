#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, m, q, cnt, ans[3010][3010], fa[10010];
int map[50010][3], last[10010], top, vis[10010];

void add(int a, int b, int c) {
	top++;
	map[top][0] = b;
	map[top][1] = c;
	map[top][2] = last[a];
	last[a] = top;
}

struct HEHE{
	int a;
	int b;
	int v;
}e[50010];

int min(int i, int j) {
	return i > j ? j : i;	
}

int find(int x) {
	if (fa[x] != x) 
		fa[x] = find(fa[x]);
	return fa[x];	
}

int cmp(const void * i, const void * j) {
	struct HEHE * c = (struct HEHE *)i;
	struct HEHE * d = (struct HEHE *)j;
	return c -> v < d -> v;	
}

void dfs(int fr, int u, int dis) {
	int i;
	vis[u] = 1;
	ans[fr][u] = ans[u][fr] = dis;
	for (i = last[u]; i; i = map[i][2]) {
		if (vis[map[i][0]]) continue;
		if (dis == -2) dis = map[i][1];
		dfs(fr, map[i][0], min(dis, map[i][1]));
	}	
}

int main() {
	int i, j, fr, to, x, y;
	freopen("truck.in", "r", stdin);
	freopen("truck.out", "w", stdout);
	memset(ans, -1, sizeof(ans));
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].v);	
	}
	qsort(e + 1, m, sizeof(struct HEHE), cmp);
	for (i = 1; i <= n; i++) fa[i] = i;
	for (i = 1; i <= m; i++) {
		x = find(e[i].a);
		y = find(e[i].b);
		//printf("x:%d y:%d\n", x, y);
		if (x != y) {
			cnt++;
			fa[x] = y;
			fr = e[i].a;
			to = e[i].b;
			add(fr, to, e[i].v);
			add(to, fr, e[i].v);
			//ans[fr][to] = ans[to][fr] = e[i].v;
			if (cnt == n - 1) break;
		}
	}
	scanf("%d", &q);
	for (i = 1; i <= q; i++) {
		scanf("%d%d", &fr, &to);
		memset(vis, 0, sizeof(vis));
		if (ans[fr][to] == -1) dfs(fr, fr, -2);
		printf("%d\n", ans[fr][to]);
	}
	return 0;
}



