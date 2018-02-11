#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int n,m,k,x;
int Qm(int x,int k)
{
	int ans=1,temp=x;
	while (k)
	{
		if (k&1) ans=(long long)ans*temp%n;
		temp=(long long)temp*temp%n;
		k>>=1;
	}
	return ans;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf(" %d %d %d %d",&n,&m,&k,&x);
	int ans=(x+(long long)Qm(10,k)*m)%n;
	printf("%d\n",ans);
	return 0;
}
