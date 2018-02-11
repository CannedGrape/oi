#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int h[100003],sum[100003];
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int n,i,maxn=0;
	int k=0,a=0;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>h[i];
	for(i=2;i<=n;i+=2)
	{
		if(h[i+1]>h[i]&&h[i-1]>h[i])
		{
			sum[k]=i;
			k++;
		}
		if(h[i+1]<h[i]&&h[i-1]<h[i])
		{
			
			sum[k]=i;
			k++;
		}
	}
	for(i=0;i<=k;i++)
	if(sum[i]-sum[i-1]==2) a++;
	cout<<k<<endl;
	cout<<k*3-a;
	
	return 0;
	
}
