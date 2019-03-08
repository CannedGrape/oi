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
	int a,b,c,d,e,f,g,h,i;
	if(cin>>a>>b>>c>>d)
	cout<<a+b*c+d<<endl;
	else
	{
		cout<<(a+b*c)%123456<<endl;
	}
	return 0;
}
