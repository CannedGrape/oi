#include <iostream>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define INF 0x7fffffff
using namespace std;

const int M = 100000 + 10;
const int N = 10000 + 10;
int n,m,Q;
int sz,en[N],g[M],pre[M],len[M];
int vis[N],d[N],fa[N],f[N][17],dp[N][17];
struct Query
{
    int fr,to,ans;
}q[30000 + 10];
struct Edge
{
    int fr,to,len;
}e[M];

void Ins(int u,int v,int w)
{
    pre[++sz] = en[u]; en[u] = sz;
    g[sz] = v; len[sz] = w;
}

int getfa(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = getfa(fa[x]);
}

bool cmp(Edge e1,Edge e2)
{
    return e1.len > e2.len;
}

void dfs(int u)
{
    vis[u] = 1;
    d[u] = d[f[u][0]] + 1;
    for (int i = 1; i <= 15; i++)
        f[u][i] = f[f[u][i - 1]][i - 1],dp[u][i] = min(dp[u][i - 1],dp[f[u][i - 1]][i - 1]);
    for (int i = en[u]; i; i = pre[i])
    {
        int v = g[i];
        if (v == f[u][0]) continue;
        f[v][0] = u; dp[v][0] = len[i];
        dfs(v);
    }
}

int LCA(int x,int y)
{
    if (d[x] < d[y]) swap(x,y);
    int T = d[x] - d[y];
    for (int i = 15; i >= 0; i--)
        if ((1 << i) <= T) T -= (1 << i),x = f[x][i];
    for (int i = 15; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
    if (x == y) return x;
    return f[x][0];
}

int F(int u,int v)
{
    int T = d[u] - d[v];
    int ret = INF;
    for (int i = 15; i >= 0; i--)
        if ((1 << i) <= T)
        {
            T -= (1 << i);
            ret = min(ret,dp[u][i]);
            u = f[u][i];
        }
    return ret;
}

void Init()
{
    int u,v,w;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        e[i].fr = u; e[i].to = v; e[i].len = w;
    }
    scanf("%d",&Q);
    for (int i = 1 ; i <= Q; i++)
    {
        scanf("%d%d",&u,&v);
        q[i].fr = u; q[i].to = v;
    }
}

void Work()
{
    int u,v,w,uu,vv;
    sort(e + 1,e + m + 1,cmp);
    for (int i = 1; i <= m; i++)
    {
        u = e[i].fr; v = e[i].to; w = e[i].len;
        uu = getfa(u); vv = getfa(v);
        if (uu == vv) continue;
        Ins(u,v,w); Ins(v,u,w);
        fa[uu] = vv;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        vis[i] = 1;
        for (int j = en[i]; j; j = pre[j])
        {
            v = g[j];
            f[v][0] = u; dp[v][0] = len[j];
            dfs(v);
        }
    }
}

void Get_Ans()
{
    int u,v,w;
    for (int i = 1; i <= Q; i++)
    {
        u = q[i].fr; v = q[i].to;
        if (getfa(u) != getfa(v))
        {
            q[i].ans = -1;
            continue;
        }   
        w = LCA(u,v);
        q[i].ans = min(F(u,w),F(v,w));
    }
    for (int i = 1; i <= Q; i++)
        printf("%d\n",q[i].ans);
}

int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    Init();
    Work();
    Get_Ans();
    return 0;
}
