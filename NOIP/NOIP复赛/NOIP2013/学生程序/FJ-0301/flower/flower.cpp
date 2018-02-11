#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1001;
int n, a[MAXN] = {0x3F3F3F3F};
bool f[2][MAXN][2];
std::vector<int> b[MAXN];
int run()
{
  for (int i = 0; i <= n; ++i) b[i].clear();
  memset(f, 0, sizeof(f));
  int w = 0;
  f[w][0][0] = f[w][0][1] = true;
  b[0].push_back(0);
  for (int i = 1; i <= n; ++i)
  {
    w = 1-w;
    f[w][0][0] = true;
    for (int j = 1; j <= i; ++j)
    {
      f[w][j][0] = f[1-w][j][0] || f[1-w][j][1];
      bool flag = false;
      if (j&1)
        for (std::vector<int>::reverse_iterator iter = b[j-1].rbegin(); iter != b[j-1].rend() && !flag; ++iter)
          flag = flag || a[i] < a[*iter];
      else
        for (std::vector<int>::reverse_iterator iter = b[j-1].rbegin(); iter != b[j-1].rend() && !flag; ++iter)
          flag = flag || a[i] > a[*iter];
      f[w][j][1] = flag;
      if (flag)
        b[j].push_back(i);
    }
  }
  for (int j = n; j >= 1; --j)
    if (f[w][j][0] || f[w][j][1]) return j;
  return -1;
}
int main()
{
  freopen("flower.in", "r", stdin);
  freopen("flower.out", "w", stdout);
  
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);
  
  const int ans1 = run();  
  for (int i = 1; i <= n; ++i) a[i] = -a[i];
  const int ans2 = run();
  
  printf("%d\n", std::max(ans1, ans2));
  
  fclose(stdin);fclose(stdout);
}
