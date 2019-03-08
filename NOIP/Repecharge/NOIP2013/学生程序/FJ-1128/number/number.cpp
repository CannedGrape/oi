#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n,p,a[1000001];
long long b[1000001],c[1000001],d[1000001],Max;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),d[i]=d[i-1]+a[i];
	c[1]=c[0]=a[1];  b[0]=b[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
		    if(i!=1)
		    {
			    if(j!=0)b[i]=max(b[i],max(b[j],d[i]-d[j]));
			    else b[i]=d[i]-d[j];
			}
			else b[i]=d[i]-d[j];
		    if(i!=1)
		    {
			    if(j!=0)c[i]=max(c[i],b[j]+c[j]);
			    else c[i]=b[j]+c[j];
			}
		}
		if(Max!=0)Max=max(Max,c[i]);
		else Max=c[i];
	}
	cout<<Max%p<<endl;
	return 0;
}
