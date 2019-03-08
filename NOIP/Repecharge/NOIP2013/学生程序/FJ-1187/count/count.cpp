#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int num[12];
void f(int a)
{
	while(a>0)
	{
		num[a%10]++;
		a/=10;
	}
}
int main()
{
	int n,x;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf(" %d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		f(i);
	}
	printf("%d\n",num[x]);
	return 0;
}
