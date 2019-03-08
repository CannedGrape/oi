#include<iostream>
#include<cstdio>
using namespace std;
int a[1000001],b[1000001],c[1000001],n,p,Max;
void search(int k,int u,int s)
{
	for (int i=k;i<=u;i++)
	    {
		 s=s+a[i];
		 k=i+1;
		 if (s>Max)
		    Max=s;
		 search(k,u,s);
		}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++)
	    {
		 Max=-2000000000;
	     scanf("%d",&a[i]);
	     search(1,i,0);
	     b[i]=Max;
		}
	c[1]=b[1];
	for (int i=2;i<=n;i++)
	    {
		 Max=-2000000000;
	     for (int j=1;j<=i-1;j++)
     	     if (c[j]+b[j]>Max)
		        Max=(c[j]+b[j])%p;
		 c[i]=Max%p;
		}
	Max=-2000000000;
	for (int i=1;i<=n;i++)
        if (c[i]>Max)
	       Max=c[i]%p;
	printf("%d\n",Max%p);
	return 0;
}
