#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
long long n;
long long ans;
long long f[2000005],r[2000005];
struct s
{	long long a,b;
}p[1000005],q[1000005];
int cmp(const s &x,const s &y)
{	return x.a<y.a;
}
void addf(long long x,long long k)
{	while (x<=n)
	{f[x]+=k;
	 x+=(x&(-x));
	}
}
void addr(long long x,long long k)
{	while (x<=n)
	{r[x]+=k;
	 x+=(x&(-x));
	}
}
long long sumf(long long x)
{	long long temp=0;
	while (x>0)
	{temp+=f[x];
	 x-=(x&(-x));
	}
	return temp;
}
long long sumr(long long x)
{	long long temp=0;
	while (x>0)
	{temp+=r[x];
	 x-=(x&(-x));
	}
	return temp;
}
int main()
{	freopen ("match.in","r",stdin);
	freopen ("match.out","w",stdout);
	long long i,j;
	scanf ("%lld",&n);
	for (i=1;i<=n;i++)
	{scanf ("%lld",&p[i].a);
	 p[i].b=i;
	}
	for (i=1;i<=n;i++)
	{scanf ("%lld",&q[i].a);
	 q[i].b=i;
	}
	sort(p+1,p+n+1,cmp);
	sort(q+1,q+n+1,cmp);
	for (i=1;i<=n;i++)
	 addf(i,1),addr(i,1);
	for (i=1;i<=n;i++)
	{ans+=abs(sumf(p[i].b)-sumr(q[i].b));
	 addf(p[i].b,-1),addr(q[i].b,-1);
	 ans=ans%99999997;
	}
	printf ("%lld\n",ans);
	return 0;
}
