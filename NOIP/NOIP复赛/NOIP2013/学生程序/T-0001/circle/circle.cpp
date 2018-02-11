#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdlib>
using namespace std;
int n,m,k,x,jia,ans,yu;
int s(int x)
{
	int a=1;
	for (int i=1;i<=x;i++)a=a*10;
	return a;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	yu=1;
	for (int i=1;i<=k/8;i++)yu=yu*(100000%n);
	yu=yu*(s(k%8)%n)*(m%n);
	yu=yu%n;
	ans=(yu+x)%n;
	printf("%d",ans);
	return 0;
}
