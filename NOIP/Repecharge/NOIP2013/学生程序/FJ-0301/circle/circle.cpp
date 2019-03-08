#include <cstdio>

int n, m, k, x;
long long powmod(long long base, long long k, const long long mod)
{
  long long ans = 1;
  for (; k; k >>= 1)
  {
    if (k&1) ans = ans*base%mod;
    base = base*base%mod;
  }
  return ans;
}
int main()
{
  freopen("circle.in", "r", stdin);
  freopen("circle.out", "w", stdout);
  
  scanf("%d%d%d%d", &n, &m, &k, &x);
  printf("%d", static_cast<int>((x + powmod(10, k, n) * m) % n));
  
  fclose(stdin);fclose(stdout);
}
