#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ll long long
using namespace std;
ll n,m,k,x;
ll qm(ll x)
{
	if (x==0) return 1;
	ll t=qm(x>>1);
	if (x&1) return (t*t*10)%n;
	return (t*t)%n;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin >> n >> m >> k >> x;
	cout << (x+(qm(k)*m)%n)%n << endl;
	return 0;
}
