#include<iostream>
#include<stdio.h>
using namespace std;
long long n,m,k,x;
void init()
{
  scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
}
long long ksm(long long a,long long b,long long c)
{
  long long base=a;
  long long result=1;
  while(b)
  {
    if(b&1)
      result=result*base%c;
    base=base*base%c;
    b=b>>1;
  }
  return result;
}
int main()
{
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  init();
  long long cf=ksm(10,k,n*m);
  cout<<(x+m*cf)%n;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
