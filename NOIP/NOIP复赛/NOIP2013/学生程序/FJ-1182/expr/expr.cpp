#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{	
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int a,c,i=0,m;
	string b;
	cin>>a;
	while(cin>>b>>c) 
	{
		if(b=="+") a=a+c;
		if(b=="*") a=a*c;
    }
	cout<<(a+m+c)%10000<<endl;
	return 0; 
}
