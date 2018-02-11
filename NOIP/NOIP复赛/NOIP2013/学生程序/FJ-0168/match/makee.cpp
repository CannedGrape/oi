#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int a[100003];
int main()
{
	freopen("match.in","w",stdout);
	int n,m;
	srand(time(0));
	n=1000;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)a[i]=i;
	random_shuffle(a+1,a+1+n);
	for(int i=1;i<=n;i++)printf("%d ",a[i]*10000);
//	for(int i=1;i<=n;i++)printf("%d ",i*1000);
	puts("");
	random_shuffle(a+1,a+1+n);
	for(int i=1;i<=n;i++)printf("%d ",a[i]*1000);
//	for(int i=1;i<=n;i++)printf("%d ",(n-i+1)*10000);
	return 0;
}
