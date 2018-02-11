#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define REP(i,n) for(int i = 0; i < n; i++)

const int inf = (1<<29);
void answer(bool out, int v) {
  printf("%s\n%d\n", out ? "Yes" : "No", v);
  exit(0);
}

int d[18][300001];
int main(){
  int m, s, t;
  freopen("escape.in", "r", stdin);
  freopen("escape.out", "w", stdout);
  scanf("%d%d%d", &m, &s, &t);
  int ti = 0, dist = 0;
  while(m >= 10) {
    m -= 10; dist += 60;
    if(dist >= s) answer(true, ti+1);
    if(++ti == t) answer(false, dist);
  }

  memset(d, 0, sizeof(d));
  REP(j,14) d[j][ti] = -inf; d[m][ti] = dist;

  for(int i = ti; i < t; i++) {
    REP(j,14) d[j][i+1] = -inf;
    REP(j,14) {
      d[j][i+1] >?= d[j][i] + 17;
      d[j+4][i+1] >?= d[j][i];
      if(j >= 10) d[j-10][i+1] >?= d[j][i] + 60; 
    }
    REP(j,14) if(d[j][i+1] >= s) answer(true, i+1);
  }
  int max = 0;
  REP(j,14) max >?= d[j][t];
  answer(false, max);
  return 0;
}
