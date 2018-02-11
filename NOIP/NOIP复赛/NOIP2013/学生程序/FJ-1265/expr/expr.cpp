#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
char a[20];
int main()
{
	int n;
	long long s;
	s=0;
	freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
	gets(a);
	n=strlen(a);
	for(int i=0;i<n;i+=2)
	{a[i]=a[i]-48;}
	for(int i=1;i<n;i+=2)
	{
		if(a[i]=='*')
	    {s=s+a[i-1]*a[i+1];a[i+1]=a[i]*a[i+1];}
	}
	for(int i=1;i<n;i+=2)
	{
		if(a[i]=='+')
		{
			s=s+a[i-1]+a[i+1];
		}
	}
	cout<<s%10000;
	fclose(stdin);
    fclose(stdout);
}
