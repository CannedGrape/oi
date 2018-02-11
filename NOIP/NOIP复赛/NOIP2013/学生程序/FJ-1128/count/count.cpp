#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n,x,sum;
void check(int i)
{
    while(i>0)
    {
	    if((i%10)==x)sum++;
	    i/=10;
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		check(i);
	}
	printf("%d\n",sum);
	return 0;
}
