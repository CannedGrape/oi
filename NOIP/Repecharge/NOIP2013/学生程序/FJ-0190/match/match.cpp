#include <cstdio>
#include <cstdlib>

using namespace std;

#define N 100010

int n,a[N],b[N],c[N],d[N],s=0;

inline void sc(int l,int r)
{
	int i=l,j=r,x=c[(l+r)>>1],t;
	while (i<=j)
	{
		while (c[i]<x) ++i;
		while (c[j]>x) --j;
		if (i<=j)
			t=c[i],c[i++]=c[j],c[j--]=t;
	}
	if (i<r) sc(i,r);
	if (l<j) sc(l,j);
}

inline void sd(int l,int r)
{
	int i=l,j=r,x=d[(l+r)>>1],t;
	while (i<=j)
	{
		while (d[i]<x) ++i;
		while (d[j]>x) --j;
		if (i<=j)
			t=d[i],d[i++]=d[j],d[j--]=t;
	}
	if (i<r) sd(i,r);
	if (l<j) sd(l,j);
}

inline int f(int x)
{
	int l=1,r=n,m,t;
	while (l<r)
	{
		if (c[r]==x) return r;
		m=(l+r)>>1,t=c[m];
		if (t==x) return m;
		else
		if (t<x) l=m; else r=m;
	}
	return l;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),c[i]=a[i];
	for (int i=1;i<=n;++i) scanf("%d",&b[i]),d[i]=b[i];
	sc(1,n),sd(1,n);
	for (int i=1;i<=n;++i)
		if (b[i]==d[f(a[i])]) ++s;
	printf("%d\n",(n-s-1)%99999997);
	return 0;
}
