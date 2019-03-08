#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long n,p,a[1000010]={0},b[1000010]={0},c[1000000]={0},ax;

int kp(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(c[j]>c[i]) {int t;t=c[i];c[i]=c[j];c[j]=t;}
		}
	}
}

int kp1(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>a[i]) {int t;t=a[i];a[i]=a[j];a[j]=t;}
		}
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>n >>p;
	for(int z=1;z<=n;z++)
	{
		cin >>a[z];
		c[z]=a[z];
	}
	for(int z=1;z<=n;z++)
	{
		kp(z);
		b[z]=a[1];
		int l=2;
		while(a[l]>0&&l<=z)
		{
			b[z]=b[z]+a[l];
			l++;
		}
	}
	for(int z=1;z<=n;z++)
	{
		c[z]=0;
	}
	a[1]=b[1];c[1]=a[1]+b[1];
	a[2]=c[1];c[2]=a[2]+b[2];
	for(int z=3;z<=n;z++)
	{
		kp(z-1);
		a[z]=c[1];
		c[z]=a[z]+b[z];
	}
	kp1(n);
	if(a[1]<0) cout <<"-";
	a[1]=abs(a[1]);
	cout <<a[1]%p <<endl;
	return 0;
}
