#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int n,m,k,x;

int gcd(int a,int b)
{
	if (a%b!=0) return (gcd(b,a%b));
	return b;
}

int main()
{
	int i,j,temp,t;
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	if (m==0 || m==n-1) {printf("%d\n",x); return 0;}
	temp=gcd(n,m);
	t=n/temp;
	j=1;
	for (i=1;i<=k;i++)
	{
		j*=10;
		j%=t;
		if (j==0||j==1) break;
	}
	if (j==0){printf("%d\n",(x+(j*m))%n); return 0;}
	k%=j;
	j=1;
	for (i=1;i<=k;i++)
	{
		j*=10;
		j%=t;
	}
	printf("%d\n",(x+(j*m))%n);
	return 0;
} 
