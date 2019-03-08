#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define F(i,j,k) for(i=j;i<=k;i++)
using namespace std;
long long p;
int mi(int x,int g)
{
	if(x==1)return 10%g;
	if(x==2)return 100%g;
	if(x%2==0)return (mi(x/2,g)^2)%g;
	if(x%2==1)return (mi(x/2,g)*mi(x/2+1,g))%g;
}
int gcd(int a,int b)
{
	if(a%b==0)return b;
	gcd(b,a%b);
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
    int n,m,x,i,j,f,g,minn;
    long long k;
	cin>>n>>m>>k>>x;
	g=gcd(n,m);
	minn=n/g;
	p=mi(k,minn);
	p-=2;
	f=p%minn;
	F(i,1,f)
	{
		x=(x+m)%n;
	}
	cout<<x<<endl;
	return 0;
}
