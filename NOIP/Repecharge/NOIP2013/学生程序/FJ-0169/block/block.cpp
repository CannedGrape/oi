#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[100001];
int f[100001];



int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	f[0]=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<=a[i-1])
		{
			f[i]=f[i-1];
		}
		else
		{
			f[i]=f[i-1]+(a[i]-a[i-1]);
		}
	}
	
	printf("%d\n",f[n]);
	
	return(0);
}

