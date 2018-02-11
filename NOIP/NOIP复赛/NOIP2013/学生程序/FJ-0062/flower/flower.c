#include"stdio.h"
long long a[100010],pre,ansf,anss;
int n,i;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ansf=1;pre=a[1];
	for(i=2;i<=n;i++)
	{
		if(ansf%2==1)
		{
			if(a[i]<pre)ansf++;
		}
		else 
		{
			if(a[i]>pre)ansf++;
		}
		pre=a[i];
	}
	anss=1;pre=a[1];
	for(i=2;i<=n;i++)
	{
		if(anss%2==1)
		{
			if(a[i]>pre)anss++;
		}
		else 
		{
			if(a[i]<pre)anss++;
		}
		pre=a[i];
	}
	if(ansf>anss)printf("%lld\n",ansf);
	else printf("%lld\n",anss);
	return 0;
}
	
		
