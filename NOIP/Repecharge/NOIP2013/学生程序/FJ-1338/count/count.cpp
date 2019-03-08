#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
//freopen("count.in","r",stdin);
//freopen("count.out","w",stdout);
int main()
{
	int x,n,y;
	cin>>n>>x;
	if(n=x)
	{
		cout<<1<<endl;
		}
		else
		if(n>10*x)
		{
			cout<<2<<endl;
			}
			else
	if(n/10>=x)
	{
		cout<<1+10+(n/10)<<endl;
	}
	return 0;
}
