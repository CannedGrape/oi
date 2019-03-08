#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,k,x,a[10000004],b[10000004];
long long tp=0,ans=0;
void init()
{
    scanf("%d%d%d%d",&n,&m,&k,&x);
}
void work()
{
	if (k<7)
	{
		int temp=1;
	    for (int i=1;i<=k;i++)  temp*=10;
	    printf("%d",((m*temp)%n+x)%n);
	}
	else
	{
		int t=0;
	    a[k]=1;
	    for (int i=k;i>=0;i--)
	    {
		    t+=a[i];
		    if (t>=n)
			{
			    b[i]=t/n;
				b[i]*=n;
				for (int j=i;b[j]>=10;j++)
				{
				    b[j+1]+=b[j]/10;b[j]=b[j]%10;
				}
				t%=n;
			}
		    t*=10;
		}
		for (int i=0;i<=k;i++)
		{
		    if (a[i]-b[i]<0)  a[i+1]--,a[i]+=10;
		    b[i]=a[i]-b[i];
		}
		long long kk=1;
		for (int i=0;i<=k;i++)
			tp+=kk*b[i],kk*=10;
		ans=(long long)(tp*m+x)%n;
		printf("%lld",ans);
	}
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	init();
	work();
	return 0;
}
//80 over
