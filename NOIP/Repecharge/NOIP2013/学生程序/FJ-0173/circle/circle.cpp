#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
long long t,n,m,k,x;
int tt,tn,tm,tk,tx;
long long qm(long long a,int b,int c)
{
	long long s=1,r=a;
	while (b>0)
	{
		if (b&1) s=s*r%c;
		r=r*r%c;
		b>>=1;
	}
	return s;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&tn,&tm,&tk,&tx);
	n=tn;m=tm;k=tk;x=tx;
	t=(qm(10,tk,tn)*m%n+x)%n;
	tt=t;
	printf("%d\n",tt);
	return 0;
}

