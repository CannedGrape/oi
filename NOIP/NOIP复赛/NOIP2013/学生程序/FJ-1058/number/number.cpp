#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
long long j,a[1000001],b[1000001],c[1000001],n,p;
long long tryy(int begin,int over)
{
	if(begin==over)return a[begin];
	long long ans=0,tel=0;
	for(j=begin;j<=over;j++)
	{
		if(a[j]+tel>0)
		{
			tel+=a[j];
			if(tel>ans)
				ans=tel;
		}
		else
		{
			tel=0;
		}
	}
	tel=0;
	for(j=over;j>=begin;j--)
	{
		if(a[j]+tel>0)
		{
			tel+=a[j];
			if(tel>ans)
				ans=tel;
		}
		else
		{
			tel=0;
		}
		
	}
	return ans;
}
long long maxx(int begin,int over)
{
	long long maxx1=-1000000000;
	if(begin==over)
		return b[begin]+c[begin];
	else
		for(int i=1;i<=over;i++)
		{
			if(maxx1<c[i]+b[i])
				maxx1=c[i]+b[i];
		}
	return maxx1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=tryy(1,i);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)
			c[i]=b[i];
		else
			if(i==2)
				c[i]=c[1]+b[1];
			else
				c[i]=maxx(1,i-1);
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]>c[n])
			c[n]=c[i];
	}
	while(c[n]>p)
		c[n]-=p;
	cout<<c[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
