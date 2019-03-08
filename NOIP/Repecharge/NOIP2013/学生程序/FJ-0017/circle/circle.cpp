#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define ifn(x) if(!x)
using namespace std;
typedef long long ll;
const ll llinf=0x7fffffffffffffffll;
const int inf=0x3fffffff,upinf=0x7fffffff;
const double dinf=1e20,eps=1e-12;

ll n,m,k,x;
ll powm(ll a, ll p, ll mode)
{
           if(p==0) return 1;
           ll r=1,base=a%mode;
           for(;p>0;p>>=1) r=(p&1)?(r*base)%mode:r,base=(base*base)%mode;
           return r;
}
int main()
{
    freopen("circle.in","r",stdin); freopen("circle.out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    printf("%lld\n",((x%n)+(powm(10,k,n)*(m%n)))%n);
    fclose(stdin); fclose(stdout);
    return 0;
}

