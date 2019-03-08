#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,b,x;
long long n1,b2;
int get_10_k(int c)
{
	int i,j;
	long long now_get,ans_get;
	now_get=10;
	ans_get=m;
	while(c!=0)
	{
		i=c&1;
		c=c>>1;
		if(i==1)
		{
			ans_get*=now_get;
			ans_get%=n1;
		}
		now_get=now_get*now_get;
		now_get%=n1;
	}
	ans_get+=x;
	ans_get%=n;
	cout<<ans_get<<endl;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&b,&x);
	n1=n;
	get_10_k(b);
	return 0;
}