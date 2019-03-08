#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

#define N 100010

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int n,h[N];
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&h[i]);
	double d=n*1.0;
	printf("%d\n",int(d*0.618));
	return 0;
}

