#include<iostream>
#include<stdio.h>
using namespace std;
long long max1=-0x7f,n,p,a[10000][5],b[10000],sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%I64d%I64d",&n,&p);
	int ma=-1001000;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i][1]);
		b[i]=a[i][1]+b[i-1];
	}
	a[1][2]=a[1][1];
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			for(int k=j+1;k<=i;k++)
			{
				if(ma<b[k]-b[j]) 
				      ma=b[k]-b[j];
			}
		}
		a[i][1]=ma;
	}
	   a[1][3]=a[1][2];
	max1=a[1][3];
	for(int i=2;i<=n;i++)
	{
		ma=-1001000;
		for(int j=1;j<i;j++)
		{
			if(ma<a[j][2]+a[j][3])
			      ma=a[j][2]+a[j][3];
		}
		a[i][3]=ma;
		if(a[i][3]>max1)
		   max1=a[i][3];
	}
	cout<<max1%p<<endl;
	return 0;
}
