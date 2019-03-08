#include<iostream> 
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,x,ans,x1;
int main ()
{
	freopen ("count.in","r",stdin);
	freopen ("count.out","w",stdout);
	scanf ("%d%d",&n,&x);
	for (int b=1;b<=n;++b)
	{
		x1=b;
		while(x1){if(x1%10==x)ans++;x1/=10;}
	}
	printf ("%d\n",ans);
	return 0;
}
