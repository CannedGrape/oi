#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int f[6]={1,20,210,2110,21110,211110};

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,x,i,m,sum=0;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
	{
	   m=i;
	   for(;m>0;m/=10) if(m%10==x) sum++;
	}
	printf("%d\n",sum);
	return 0;
} 
