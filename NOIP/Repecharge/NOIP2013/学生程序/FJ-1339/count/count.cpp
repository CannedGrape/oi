#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	const int n=1000000;
	int x,b;
	cin>>b>>x;
		if(b>=20)
		cout<<10+(b%10)<<endl;
		else
		{
			if(b>=10)
			cout<<b-9*x+2<<endl;
			else
			{
				if(b>=0)
				cout<<1<<endl;
			}
		}
	return 0;
} 
