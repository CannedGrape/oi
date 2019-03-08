/**************************
    noip2013 - Day1 - T3 truck
    Author: RsEnts
**************************/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 200010

using namespace std;

struct Edge {
    int u, v, w;
}edg[MaxN];

bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}

int Max(int a, int b) {
    return a > b ? a : b;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int N, M, Q, f[MaxN], fa[MaxN][20], g[MaxN][20], dep[MaxN], head[MaxN], v[MaxN], prep[MaxN], m0, w[MaxN], Ans;
bool vis[MaxN];

int find(int x) {
    return (f[x] == x) ? f[x] : (f[x] = find(f[x]));
}

void AddEdge(int a, int b, int c) {
    ++m0; v[m0] = b; w[m0] = c; prep[m0] = head[a]; head[a] = m0;
}

void Dfs(int now) {
    vis[now] = 1;
    for(int i = head[now]; i; i = prep[i])
        if(!vis[v[i]]) {
            fa[v[i]][0] = now;
            g[v[i]][0] = w[i];
            dep[v[i]] = dep[now] + 1;
            Dfs(v[i]);
        }
}

void PreWork() {
    int i, j;
    Dfs(0);
    for(j = 1; j <= 18; ++j)
        for(i = 0; i <= N; ++i) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            g[i][j] = Min(g[i][j - 1], g[fa[i][j - 1]][j - 1]);
        }
}

void GetLCA(int l, int r) {
    if(dep[l] < dep[r]) swap(l, r);
    int i, d = dep[l] - dep[r];
    Ans = 1000000;
    for(i = 0; d; ++i, d >>= 1)
        if(d & 1) {
            Ans = Min(Ans, g[l][i]);
            l = fa[l][i];
        }
    if(l == r)
        return ;
    for(i = 18; i >= 0; --i)
        if(fa[l][i] != fa[r][i]) {
            Ans = Min(Ans, g[l][i]);
            Ans = Min(Ans, g[r][i]);
            l = fa[l][i]; r = fa[r][i];
        }
    Ans = Min(Ans, g[l][0]); Ans = Min(Ans, g[r][0]);
}

int main() {
    freopen("truck.in", "r", stdin);
    freopen("truck.out", "w", stdout);
    int i, x1, y1;
    scanf("%d%d", &N, &M);
    for(i = 1; i <= M; ++i)
        scanf("%d%d%d", &edg[i].u, &edg[i].v, &edg[i].w);
    sort(edg + 1, edg + M + 1, cmp);
    for(i = 1; i <= N; ++i) f[i] = i;
    for(i = 1; i <= M; ++i)
        if((x1 = find(edg[i].u)) != (y1 = find(edg[i].v))) {
            AddEdge(edg[i].u, edg[i].v, edg[i].w);
            AddEdge(edg[i].v, edg[i].u, edg[i].w);
            f[x1] = y1;
        }
    for(i = 1; i <= N; ++i)
        if(find(i) == i) {
            AddEdge(0, i, -1); AddEdge(i, 0, -1);
        }
    PreWork();
    scanf("%d", &Q);
    int a1, b1;
    for(i = 1; i <= Q; ++i) {
        scanf("%d%d", &a1, &b1);
        GetLCA(a1, b1);
        printf("%d\n", Ans);
    }
    //while(1);
    return 0;
}
