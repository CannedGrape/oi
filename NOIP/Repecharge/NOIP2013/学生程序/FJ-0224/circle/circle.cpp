#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
using namespace std;
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	long long n,m,k,x;
	cin>>n>>m>>k>>x;
	long long tx=x;
	for(int i=1;i<=10;i++)tx=(tx+m)%n;
	long long l=tx-x+n;
	for(int i=1;i<=k;i++)x=(x+l)%n;
	cout<<x<<endl;
}

