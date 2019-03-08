#include<cstdio>
#include<cstring>
#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
using namespace std;
const int inf = (1<<29);
const int maxn = 301;

int n, s;
int g[maxn][maxn], d[maxn][maxn], mk[maxn][maxn];
int p[maxn];
int ans = inf;

int ecc(int st, int ed) {
  int ans = 0;
  REP(u,n) {
    int min = inf;
    FOR(k,st,ed) min <?= d[u][p[k]];
    ans >?= min;
  }
  return ans;
}

void go(int u, int v) {
  int k;
  for(p[k = 0] = u; p[k] != v; k++) {
    for(p[k+1] = 0; p[k+1] < n; p[k+1]++)
      if(g[p[k]][p[k+1]] && d[p[k]][v] == d[p[k+1]][v] + g[p[k]][p[k+1]]) break;
  }
  FOR(st,0,k) FOR(ed,st,k) {
    int x = p[st], y = p[ed];
    if(d[x][y] <= s && !mk[x][y]) {
      mk[x][y] = mk[y][x] = 1;
      ans <?= ecc(st, ed);
    }
  }
}

int main(){
  freopen("core.in", "r", stdin);
  freopen("core.out", "w", stdout);
  scanf("%d%d", &n, &s);
  REP(i,n) REP(j,n) g[i][j] = inf;
  REP(i,n-1) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u-1][v-1] = g[v-1][u-1] = w;
  }
  REP(i,n) REP(j,n) d[i][j] = g[i][j];
  REP(i,n) d[i][i] = 0;
  REP(k,n) REP(i,n) REP(j,n) d[i][j] <?= d[i][k] + d[k][j];
  int diam = 0;
  REP(i,n) REP(j,n) diam >?= d[i][j];
  memset(mk, 0, sizeof(mk));
  REP(i,n) REP(j,n) if(diam == d[i][j]) go(i,j);
  printf("%d\n", ans);
  return 0;
}
