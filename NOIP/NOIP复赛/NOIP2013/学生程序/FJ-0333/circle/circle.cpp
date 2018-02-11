#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
long long power(long long a, long long b, long long p) {
  long long tmp = 1LL;
  while (b > 0) {
    if (b % 2 == 1) tmp = (tmp * a) % p;
    b = b / 2;
    a = (a * a) % p;
  }
  return tmp;
} 
long long n,m,ans,k,ts,x;
int main() {
  freopen("circle.in","r",stdin); freopen("circle.out","w",stdout);
   scanf("%lld%lld%lld%lld", &n,&m,&k,&x);
   m %= n;
   ts = power(10,k,n);
   ans = (x + ts * m % n) % n;
   printf("%lld",ans);
 fclose(stdin); fclose(stdout);
}
   
