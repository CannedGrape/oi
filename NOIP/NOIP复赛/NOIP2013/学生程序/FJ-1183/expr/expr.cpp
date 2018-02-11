#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
long long x[100002];
int i=2;
char y[100001];
using namespace std;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>x[1];
	x[1]=x[1]%10000;
	while(cin>>y[i])
	{
		cin>>x[i];
		x[i]=x[i]%10000;
		if (y[i]=='*') x[i-1]=x[i-1]*x[i],x[i-1]=x[i-1]%10000,x[i]=0,i--;
		i++;
	}
	for (int j=2;j<=i;j++) x[1]+=x[j];
	x[1]=x[1]%10000;
	cout<<x[1];
	return 0;
}
