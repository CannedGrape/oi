#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n,p,Maxn;
long long f[1000002],Max,d;
long long ans[1000002],s;
bool f2[1000002];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%lld",&n,&p); f[0]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&d);
		if (f2[i-1])
		{
			if (d<0)f2[i]=0,f[i]=f[i-1];
			else f2[i]=1,f[i]=f[i-1]+d;
		}
		else
		{
			if (d<0)f2[i]=0,f[i]=f[i-1];
			else
			{
				if (d>f[i-1])f[i]=d,f2[i]=1;
				else f[i]=f[i-1],f2[i]=0;
			}
		}
		if (i==1)f[1]=ans[1]=s=d,Max=f[1],Maxn=1;
		else
		{
			ans[i]=Max+ans[Maxn];
			if (Max<f[i])Maxn=i,Max=f[i];
			s=s<ans[i]?ans[i]:s;
		}
	}
	printf("%lld\n",(long long)s%p);
	return 0;
}
