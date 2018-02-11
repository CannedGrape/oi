#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long n,m,k,x;
long long a[100];


int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	
	cin>>n>>m>>k>>x;
	
	a[0]=10;
	int jsq=0;
	long long s=k;
	for (;s>0;s/=2)
	{
		jsq++;
		a[jsq]=a[jsq-1]*a[jsq-1];
		a[jsq]%=n;
	}
	
	
	s=k;
	long long cg=1;
	jsq=0;
	for (;s>0;s/=2)
	{
		if (s%2!=0)
		{
			cg*=a[jsq];
			cg%=n;
		}
		jsq++;
	}
	
	cg*=m;
	cg%=n;
	cg+=x;
	cg%=n;
	cout<<cg<<endl;
	
	return(0);
}

