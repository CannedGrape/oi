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
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	const int q=1000;
	int n,p,a[q],b,right;
	cin>>n>>p;
	right=n;
	for(int b=1;b<=n;b++)
	cin>>a[b];
	cout<<5*n-4<<endl;
	return 0;
}
