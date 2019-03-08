#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100001;
struct Match { int length, index; };
inline bool operator<(const Match& lhs, const Match& rhs)
  { return lhs.length < rhs.length; }
int n, x[MAXN], y[MAXN];
long long ans;
Match a[MAXN], b[MAXN];
int main()
{
  freopen("match.in", "r", stdin);
  freopen("match.out", "w", stdout);
  
  scanf("%d", &n);
  for (int i = 1; i <= n; a[i].index = i, ++i) scanf("%d", &a[i].length);
  for (int i = 1; i <= n; b[i].index = i, ++i) scanf("%d", &b[i].length);
  std::sort(a+1, a+n+1);
  std::sort(b+1, b+n+1);
  for (int i = 1; i <= n; ++i) x[a[i].index] = i;
  for (int i = 1; i <= n; ++i) y[b[i].index] = i;
  
  for (int i = 1, j; i <= n; ++i)
  {
    for (j = i; j <= n && y[j] != x[i]; ++j);
    for (int k = j; k > i; --k, ++ans)
      std::swap(y[k], y[k-1]);
  }
  printf("%d", static_cast<int>(ans % 99999997));
  
  fclose(stdin);fclose(stdout);
}
