#include<iostream> 
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,p,tz,ans,a,fs[10000001],ans1,f[10000001],tz1[10000001],ans2;
int main ()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	scanf ("%d%d",&n,&p);
	for (int b=1;b<=n;++b)
	{
		scanf ("%d",&a);
		if (b==1){tz=a;fs[b]=a;ans=a+a;f[b]=a;tz1[b]=a;ans2=a;}
		else
		{
			ans=ans>(fs[b-1]+tz1[b-1])?ans:(fs[b-1]+tz1[b-1]);
			if (f[b-1]>0)f[b]=f[b-1]+a;
			else f[b]=a;
			tz=tz>f[b]?tz:f[b];
			tz1[b]=tz;
			fs[b]=ans;
			ans2=ans2>fs[b]?ans2:fs[b];
		}
	}
	ans1=abs(ans2);ans1%=p;
	if (ans2<0)printf ("%c",'-');
	printf ("%d\n",ans1);
	return 0;
}
