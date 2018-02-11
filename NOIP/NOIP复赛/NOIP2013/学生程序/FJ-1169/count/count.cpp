#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int n,x,ans=0;
int solve(int p)
{
	int sum=0;
	while(p>0)
	{
		if (p%10==x)sum++;
		p/=10;
	}
	return sum;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
	for (int i=1;i<=n;i++) ans+=solve(i);
	printf("%d\n",ans);
	return 0;
}
