#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n,p,a[1000001];
long long f[1000001],b[10000001],t,s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0]=0;
	for(i=1;i<=n;i++)
	{
		if(f[i-1]>=0)
		{
			f[i]+=f[i-1]+a[i];
		}
		else f[i]+=a[i];
	}
	b[1]=f[1];t=2*b[1];s=b[1];
	for(i=2;i<=n;i++)
	{
		b[i]=t;
		if(b[i]+f[i]>t) t=b[i]+f[i];
		if(s<b[i]) s=b[i];
	}
	s=s%p;
	printf("%lld\n",s);
	return 0;
}
