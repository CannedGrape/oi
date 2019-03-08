#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring> 
#include <iostream>
#include <algorithm>
using namespace std;
int n, big, m=1;
int a[1000001] = {}, b[1000001] = {}, c[1000001] = {};
int main ()
{
	freopen("number.in" ,"r", stdin);
	freopen("number.out" ,"w", stdout);
	cin>>n>>m;
	for (int i = 1; i <= n; i ++)
	{	
		cin>>a[i];
		a[i]=a[i]%m;
	}
	b[1] = a[1];
	for (int i = 2; i <= n; i ++)
	{
		if (a[i]>0 && b[i-1]>0) b[i] = (a[i]+b[i-1])%m;
		if (a[i]>0 && b[i-1]<0) b[i] = (a[i])%m;
		if (a[i]<0 && b[i-1]>0) b[i] = (a[i]+b[i-1])%m;
		if (a[i]<0 && b[i-1]<0) b[i] = (a[i])%m;
	}
	c[1] = b[1];
	c[2] = (b[1]+c[1])%m;
	big = c[2];
	for (int i = 3; i <= n; i ++)
	{
		c[i]=max(big,(c[i-1]+b[i-1])%m);
		if (c[i] > big) big = c[i];
	}
	cout<<max(big, c[1]);
	fclose(stdin);		
	fclose(stdout);
	return 0;
}
