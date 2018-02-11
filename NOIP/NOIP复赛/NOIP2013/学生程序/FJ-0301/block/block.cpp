#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100001;
int n, a[MAXN], tmp[MAXN];
long long ans;
inline bool cmp(const int lhs, const int rhs) { return a[lhs] < a[rhs]; }
int main()
{
  freopen("block.in", "r", stdin);
  freopen("block.out", "w", stdout);
  
  scanf("%d", &n);
  for (int i = 1; i <= n; tmp[i] = i, ++i)
    scanf("%d", a+i);
  std::sort(tmp+1, tmp+n+1, cmp);
  for (int i = 1; i <= n; ++i)
  {
    int idx = tmp[i], lef = idx, rig = idx;
    while (lef > 1 && a[lef-1] > 0) --lef;
    while (rig < n && a[rig+1] > 0) ++rig;
    const int delta = a[idx];
    ans += delta;
    for (int j = lef; j <= rig; ++j) a[j] -= delta;
  }
  printf("%lld\n", ans);
  
  fclose(stdin);fclose(stdout);
}
