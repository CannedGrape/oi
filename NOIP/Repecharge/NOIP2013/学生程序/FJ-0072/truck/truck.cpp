#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define MAX_N 10010
#define MAX_M 200020

using namespace std;

struct EDGE
{
    EDGE(int to, int w, EDGE *next): to(to), w(w), next(next) {}
    
    int to, w;
    EDGE *next;
};

int x[MAX_N], y[MAX_N], z[MAX_N], fa[MAX_N], rank[MAX_N];
bool state[MAX_N];
EDGE *st[MAX_N];
int n, m, q;

void ae(int u, int v, int w)
{
    st[u] = new EDGE(v, w, st[u]);
}

void qsort(int l, int r)
{
    int i = l, j = r, m = z[(l + r) / 2];
    while (i <= j)
    {
        while (z[i] > m) i++;
        while (z[j] < m) j--;
        if (i <= j)
        {
            swap(x[i], x[j]);
            swap(y[i], y[j]);
            swap(z[i], z[j]);
            i++; j--;
        }
    }
    if (l < j) qsort(l, j);
    if (i < r) qsort(i, r);
}

int dfs(int now, int to, int ans)
{
    int tmp;
    state[now] = 1;
    if (now == to) return ans;
    for (EDGE *e = st[now]; e; e = e->next)
        if (!state[e->to])
        {
            tmp = dfs(e->to, to, min(ans, e->w));
            if (tmp != -2)
                return tmp;
        }
    return -2;
}

void Triv()
{
    int u, v;
    scanf("%d", &q);
    while (q--)
    {
        memset(state, 0, sizeof(state));
        scanf("%d%d", &u, &v);
        printf("%d\n", dfs(u, v, 99999999));
    }
}

int find(int x)
{
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void link(int x, int y)
{
    if (rank[x] < rank[y]) swap(x, y);
    fa[y] = x;
    rank[x] = max(rank[x], rank[y] + 1);
}

int main()
{
    freopen("truck.in", "r", stdin);
    freopen("truck.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
    
    for (int i = 2; i <= n; i++)
    {
        m++;
        x[m] = 1; y[m] = i; z[m] = -1;
    }
    
    qsort(1, m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        if (find(x[i]) != find(y[i]))
        {
            link(x[i], y[i]);
            ae(x[i], y[i], z[i]);
            ae(y[i], x[i], z[i]);
        }
    }
    
    Triv();
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
