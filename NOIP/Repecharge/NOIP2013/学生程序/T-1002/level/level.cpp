#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	int n,m,a[10000]={0},b,i,sum=0;
	cin>>n>>m;
	for(i=1;i<=4*m+1;i++)
	{
	cin>>b;
	a[b]++;
	}
	sort(a,a+n);
	for(i=n-1;i>=1;i--)
	if(a[i]!=a[i+1])sum++;
	cout<<sum<<endl;
	return 0;
}

