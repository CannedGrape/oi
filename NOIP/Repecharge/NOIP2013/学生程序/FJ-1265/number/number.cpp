#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int a[1000000];
int main()
{
	int d,n,m,s=0;
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{cin>>a[i];}
	d=a[n]*a[n-1]+a[1];
	cout<<d%m;
	fclose(stdin);
    fclose(stdout);
}
