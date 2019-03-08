#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100001],b[100001],c[100001],d[100001];
int main()
{
	int n,p,s1=0,s2=0;
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>n;
	cin>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	b[1]=a[1];
	s1=a[1];
	int max=s1;
	for(int i=2;i<=n;i++)
	{
		s1+=a[i];
		if(s1>=max)
		{
		max=s1;
		b[i]=s1;
		}
		else 
		b[i]=a[i];
	}
	c[1]=b[1];
	s2=c[1];
	int max2=s2;
	for(int i=2;i<=n;i++)
	{
		s2=b[i-1]+c[i-1];
		if(s2>=max2)
		{
		max2=s2;
		c[i]=s2;
	    }
	    else 
	    c[i]=b[i];
	
	}
	if(c[n]>=0)
	cout<<c[n]%p<<endl;
	if(c[n]<0)
	cout<<"-"<<(0-c[n])%p<<endl;
	fclose(stdin);
	fclose(stdout);
}
