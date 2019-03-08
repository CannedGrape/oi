#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,k,x;

int qsm(int k)
{
	if (k==0)
	{
		return 1;
	}
	if (k==1)
	{
		return 10;
	}
	int ans=qsm(k/2);
	if (k%2==0)
	{
		return (int)( (long long)ans * (long long)ans & (long long) n);
	}
	else
	{
		return (int)( ( ( (long long)ans * (long long)ans % (long long)n ) * (long long)10 ) % (long long)n );
	}
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%d\n",(x+(int)((long long)qsm(k) * (long long)m % (long long)n))%n);
	//system("pause");
	return 0;
}
