#include <cstdio>
int n,m,k,x,ans,base;
int main()
{
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  scanf("%d%d%d%d",&n,&m,&k,&x);
  ans=1; base=10;
  for (;k;k>>=1)
  {
    if (k&1) ans=(long long)ans*base%n;
    base=(long long)base*base%n;
  }
  ans=(long long)ans*m%n;
  ans=(ans+x)%n;
  printf("%d\n",ans);
  return 0;
}
