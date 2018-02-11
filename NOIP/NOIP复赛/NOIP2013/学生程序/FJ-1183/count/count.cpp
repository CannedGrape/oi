#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
int a,b,h=0;
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>a>>b;
	int x=1;
	if (a>9) h=1,x=10;
	if (a>99) h=20,x=100;
	if (a>999) h=300,x=1000;
	if (a>9999) h=4000,x=10000;
	if (a>99999) h=50000,x=100000;
	if (a>999999) h=600000,x=1000000;
	for (int i=x;i<=a;i++)
	{
		int x=i;
		while (x>=10)
		{
			if (x%10==b) h++;
			x=x/10;
		}
		if (x==b) h++;
	}
	cout<<h;
	return 0;
}
