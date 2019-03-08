#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n,x;
int sum=0;
int a[20];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
	int b,c;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=10;j++) a[j]=-1;
		b=i,c=1;
		while (b>=10) b=b/10,c++;
		a[1]=i%10;
		if (c>=2) a[2]=i%100/10;
		if (c>=3) a[3]=i%1000/100;
		if (c>=4) a[4]=i%10000/1000;
		if (c>=5) a[5]=i%100000/10000;
		if (c>=6) a[6]=i%1000000/100000;
		if (c>=7) a[7]=i/1000000;
		for (int j=1;j<=c;j++)
		{
			if (a[j]==x) sum++;
		}
	}
	printf("%d\n",sum);
	return 0;
}
