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
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int a,b,c,d,x=a+b+c;
	cin>>a>>b>>c>>d;
	if(x>=9999)
	cout<<x-10000<<endl;
	else
	cout<<x<<endl; 
	return 0;
}
