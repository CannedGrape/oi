#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int i,n,t,tt,s;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	t=0;
	for (i=1;i<=n;i++)
	{
		tt=t;
		scanf("%d",&t);
		if (t>tt) s+=t-tt;
	}
	printf("%d\n",s);
	return 0;
}
