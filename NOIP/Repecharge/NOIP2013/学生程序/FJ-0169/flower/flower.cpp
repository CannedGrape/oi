#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[100001];

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	int status;
	
	status=1;
	int jsq1=0;
	for (int i=2;i<=n;i++)
	{
		if (status==1)
		{
			if (a[i]<a[i-1])
			{
				jsq1++;
				status=0;
			}
		}
		else
		{
			if (a[i]>a[i-1])
			{
				jsq1++;
				status=1;
			}
		}
	}
	jsq1++;
	
	
	status=0;
	int jsq2=0;
	for (int i=2;i<=n;i++)
	{
		if (status==1)
		{
			if (a[i]<a[i-1])
			{
				jsq2++;
				status=0;
			}
		}
		else
		{
			if (a[i]>a[i-1])
			{
				jsq2++;
				status=1;
			}
		}
	}
	jsq2++;
	
	
	printf("%d\n",max(jsq1,jsq2));
	
	return(0);
}

