#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?(-(a)):(a))
#define MAX 2139062143
#define S 10000
using namespace std;
long long n,m,k,x,kk,ans;
long long qmi(long long a,long long b)
{
	long long c=1;
	while(b)
	{
		if(b&1)c=(c*a)%n;
		a=(a*a)%n;
		b/=2;
	}
	return c;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	int i,j;
	cin>>n>>m>>k>>x;
	kk=qmi(10,k);
	kk=(kk*m)%n;
	ans=(kk+x)%n;
	cout<<ans<<endl;
	return 0;
}
