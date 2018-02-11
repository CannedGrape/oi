#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdio>
using namespace std;
int a[100],p,b,n,r,enter,l=0;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>n;
    cin>>p;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    for(int j=i;j<=i;j++)
	    {
		l=a[j]+l;
	    }
	    a[i]=l;
	}
	l=1;
	for(int i=1;i<=n-1;i++)
    {
    for(int j=i;j<=i;j++)
	    {
		l=a[j]+l;
	    }
	    a[i]=l;
	}
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
		if(a[j]>a[i])
		{
			enter=a[j];
			a[j]=a[i];
			a[i]=enter;
		}
	}
	cout<<a[n]%p;
	fclose(stdin);
	fclose(stdout);
}
