#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long sum=10;
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	int n,m,k,x;
	int zq,i;
	cin>>n>>m>>k>>x;
	for(i=1;i<=n;i++)
	{
		if((x+m*i)%n==x) {zq=i;break;}
	}
	for(i=1;i<=k;i++)
	sum*=10;
	cout<<sum%zq+x<<endl;
	return 0;
	
}
