#include <cstdio>
using namespace std;
int n,s,sum;
void check (int x)
{
	while (x!=0)
	{
		if (x%10==s) sum++;
		x/=10;
	}
}
int main ()
{
	freopen ("count.in","r",stdin);
	freopen ("count.out","w",stdout);
	scanf ("%d%d",&n,&s);
	for (int i=1;i<=n;i++) check (i);
	printf ("%d\n",sum);
	return 0;
}
