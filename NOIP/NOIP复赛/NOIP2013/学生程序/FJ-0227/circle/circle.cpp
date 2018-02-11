#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

long long n,m,k,x;
long long mod;

long long gcd(long long a,long long b)
{
  if (!b) return a;
  return gcd(b,a%b);
}

long long Q_M(long long k,long long ten)
{
  long long re=1;
  while (k)
  {
    if (k%2) re=re*ten%mod;
    ten=ten*ten%mod;
    k/=2;
  }
  return re;
}

int main()
{
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  cin >>n >>m >>k >>x;
  mod=n*m/gcd(n,m);
  mod=mod/m;
  long long ten=10%mod;
  long long p=Q_M(k,ten);
  int ans=x;
  for (int i=1;i<=p;i++) ans=(ans+m)%n;
  cout <<ans <<endl;
  return 0;
}
