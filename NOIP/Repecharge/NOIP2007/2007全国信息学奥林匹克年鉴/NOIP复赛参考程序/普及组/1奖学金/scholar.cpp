#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int first[500], tot[500], rank[500];

bool before(int a, int b) {
  if(tot[rank[a]] != tot[rank[b]]) return tot[rank[a]] < tot[rank[b]];
  if(first[rank[a]] != first[rank[b]]) return first[rank[a]] < first[rank[b]];
  return rank[a] > rank[b];
}

int main() {
  freopen("scholar.in", "r", stdin);
  freopen("scholar.out", "w", stdout);
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d%d", &first[i], &x, &y);
    tot[i] = first[i] + x + y;
    rank[i] = i;
  }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(before(j, i)) swap(rank[i], rank[j]);
  for(int i = 0; i < 5; i++)
    printf("%d %d\n", rank[i]+1, tot[rank[i]]);

#ifdef CHECK_DATA
  bool flag = false;
  for(int i = 0; i < n-1; i++)
    if(tot[rank[i]] == tot[rank[i+1]]) flag = true;
  if(flag) fprintf(stderr, "Some students have the same score\n");
#endif

  return 0;
}
