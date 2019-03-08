#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cmath>
#define INF 0x7fffffff
using namespace std;

const int N = 30 + 2;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
int n,m,q,now;
int tx,ty;
int a[N][N],v[N][N][N][N],f[N][N][N][N],in[N][N][N][N];

void Init()
{
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d",&a[i][j]);
}

void DP(int sx,int sy,int ex,int ey)
{
    if (v[sx][sy][ex][ey] == now) return;
    
    if (sx == tx && sy == ty) 
    {
        v[sx][sy][ex][ey] = now;
        f[sx][sy][ex][ey] = 0;
        return;
    }
    in[sx][sy][ex][ey] = now;
    f[sx][sy][ex][ey] = INF;
    
    int nx,ny;

    for (int p = 0; p < 4; p++)
    {
        nx = ex + dx[p]; ny = ey + dy[p];
        if (!(nx >= 1 && nx <= n && ny >= 1 && ny <= m)) continue;
        if (nx == sx && ny == sy) continue;
        if (a[nx][ny] == 0) continue;
        if (in[sx][sy][nx][ny] == now) continue;
        DP(sx,sy,nx,ny);
        if (v[sx][sy][nx][ny] == now)
        {
            v[sx][sy][ex][ey] = now;
            f[sx][sy][ex][ey] = min(f[sx][sy][ex][ey],f[sx][sy][nx][ny] + 1);
        }
    }
    
    for (int p = 0; p < 4; p++)
    {
        nx = sx + dx[p]; ny = sy + dy[p];
        if (!(nx >= 1 && nx <= n && ny >= 1 && ny <= m)) continue;
        if (!(nx == ex && ny == ey)) continue;
        if (in[ex][ey][sx][sy] == now) continue;
        DP(ex,ey,sx,sy);
        if (v[ex][ey][sx][sy] == now)
        {
            v[sx][sy][ex][ey] = now;
            f[sx][sy][ex][ey] = min(f[sx][sy][ex][ey],f[ex][ey][sx][sy] + 1);
        }
    }
    
    in[sx][sy][ex][ey] = 0;
}

void Work()
{
    int ex,ey,sx,sy;
    
    memset(v,0,sizeof(v));
    memset(in,0,sizeof(in));
    
    for (int i = 1; i <= q; i++)
    {
        now = i;
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        in[sx][sy][ex][ey] = now;
        DP(sx,sy,ex,ey);
        if (v[sx][sy][ex][ey] != now) printf("-1\n");
        else printf("%d\n",f[sx][sy][ex][ey]);
    }
}

int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    Init();
    Work();
    return 0;
}
