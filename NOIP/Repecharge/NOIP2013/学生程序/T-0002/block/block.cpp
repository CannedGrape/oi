#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int s[100005];
int main()
{
	int a,i;
	long long sum=0;
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&a);
	for(i=0;i<=a;i++)
	s[i]=0;
	for(i=1;i<=a;i++)
	{	
		scanf("%d",&s[i]);
		if(s[i]-s[i-1]>0)
		sum+=(s[i]-s[i-1]);
	}
	cout<<sum;
	return 0;
}
