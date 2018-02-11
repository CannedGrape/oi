#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;
long long n,m,k,x,ans;
void Pow(long long base,long long t)
{
	ans=1;
	long long I=base;
	while (t)
	{
		if (t&1) ans=(ans*I)%n;
		I=(I*I)%n;
		t>>=1;
	}
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n>>m>>k>>x;
	Pow(10,k);
	ans=(ans*m)%n;
	ans=(ans+x)%n;
	cout<<ans;
	//system("pause");
	return 0;
}
