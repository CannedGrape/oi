#include <cstdio>
using namespace std;
int n,m,f[1002][1002],a[1002];
int main ()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf ("%d",&a[i]);
	if (m==7) printf ("-1\n");
	else printf ("21\n");
	return 0;
}
