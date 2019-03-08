#include <cstdio>
#include <cstdlib>

using namespace std;

int n,m,k,x;

inline unsigned long long g(int x)
{
	unsigned long long g=1;
	for (int i=1;i<=x;++i) g*=10;
	return g;
}

inline unsigned long long f(int m,int k)
{
	unsigned long long x=m;
	while (k>12)
		x=x*1000000000000%n,k-=12;
	unsigned long long f=x*g(k)%n;
	return f;
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%d\n",(x+f(m,k))%n);
	return 0;
}

