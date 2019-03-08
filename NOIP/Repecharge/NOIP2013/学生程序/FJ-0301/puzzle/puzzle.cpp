#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 30;
const int xy[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m, q, map[MAXN][MAXN], dist[MAXN][MAXN][MAXN][MAXN];
bool inq[MAXN][MAXN][MAXN][MAXN];
inline void get(const int data, int& ex, int& ey, int& sx, int &sy)
{
  ex = data&31;
  ey = (data>>5)&31;
  sx = (data>>10)&31;
  sy = (data>>15)&31;
}
inline int set(const int ex, const int ey, const int sx, const int sy)
{
  return ex | (ey<<5) | (sx<<10) | (sy<<15);
}
int spfa(const int EX, const int EY, const int SX, const int SY, const int TX, const int TY)
{
  if (SX == TX && SY == TY) return 0;
  memset(dist, 0x3F, sizeof(dist));
  std::queue<int> Q;
  dist[EX][EY][SX][SY] = 0, Q.push(set(EX, EY, SX, SY)), inq[EX][EY][SX][SY] = true;
  for (int ex, ey, sx, sy; !Q.empty(); Q.pop())
  {
    get(Q.front(), ex, ey, sx, sy);
    const int d = dist[ex][ey][sx][sy] + 1;
    for (int i = 0; i < 4; ++i)
    {
      int nex = ex+xy[i][0], ney = ey+xy[i][1], nsx = sx, nsy = sy;
      if (nex < 0 || ney < 0 || nex == n || ney == m || map[nex][ney] == 0) continue;
      if (nex == nsx && ney == nsy)
        nsx = ex, nsy = ey;
      if (dist[nex][ney][nsx][nsy] > d)
      {
        dist[nex][ney][nsx][nsy] = d;
        if (!inq[nex][ney][nsx][nsy])
          inq[nex][ney][nsx][nsy] = true, Q.push(set(nex, ney, nsx, nsy));
      }
    }
    inq[ex][ey][sx][sy] = false;
  }
  int ans = 0x3F3F3F3F;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      ans = std::min(ans, dist[i][j][TX][TY]);
  return ans == 0x3F3F3F3F ? -1 : ans;
}
int main()
{
  freopen("puzzle.in", "r", stdin);
  freopen("puzzle.out", "w", stdout);
  
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &map[i][j]);
  for (int ex, ey, sx, sy, tx, ty; q--; )
  {
    scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);
    printf("%d\n", spfa(ex-1, ey-1, sx-1, sy-1, tx-1, ty-1));
  }
  
  fclose(stdout);fclose(stdin);
}
