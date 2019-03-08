#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[10001],b[10001],sum;
void aaa()
{
	sum=0;
	for (int i=1; i<=n; i++)
	  for (int j=1; j<=n; j++)
	  {
	     sum+=(a[i]-b[i])*(a[i]-b[i]);
 	    
}// cout<<sum<<endl;
	}
int main()
{
	freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++)
	  cin>>a[i];
	for (int i=1; i<=n; i++)
	  cin>>b[i];
    aaa();
    int x=sum,minn=0;
    for (int k=1; k<=n; k++)
    {
		swap(a[k],a[k+1]);
		aaa();
		if (sum<x)
		{
			x=sum;
			minn=k;
		}
	}
	cout<<minn<<endl;
}
