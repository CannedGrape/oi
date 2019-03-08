#include<iostream>
#include<cstdio>
using namespace std;

int n,x,a[1000010]={0},l=1,ans=0,l1;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin >>n >>x;
	while(l1)
	{
		a[l]=l1%10;
		l1=l1/10;
		l++;
	}
	for(int z=1;z<=n;z++)
	{
		l=0;
		int l1,l2,l3=1;
		l1=z;
		while(l1)
		{
			if(l1%10==x) ans++;
			l1=l1/10;
			l++;
		}
	}
	cout <<ans <<endl;
	return 0;
}
