#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int n,s,k,zc;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		zc=i;
		while(zc!=0)
		{
			if(zc%10==k) s++;
			zc/=10;
		}
		
	}
	printf("%d\n",s);
	return 0;
}
