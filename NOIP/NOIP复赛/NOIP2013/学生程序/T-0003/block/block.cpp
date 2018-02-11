#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int h[100005],f[100005],p[100005];


int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int i,j=2,k=1;
	int n,minn=100000;
	int sum=0,a,b;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		f[i]=9;
	}
	for(i=2;i<=n;i++)
	{
		if(h[i]<minn) minn=h[i];
		if(h[i]>h[i-1]) f[i]=0;
		if(h[i]<h[i-1]) f[i]=1;
	}
	f[1]=f[2];
	
	while(j<=n)
	{
		
		if(f[j]==f[j-1])
		{
			a=h[j-1];
		
			while(f[j]==f[j-1]&&j<=n) 
			{
				p[k]=abs(h[j]-a);	
				j++;
			}
			
		}
		if(f[j]!=f[j-1]) 
		{
			if(h[j]<h[j+1]&&f[j+1]==0) f[j]=0;
			if(h[j]>h[j+1]&&f[j+1]==1) f[j]=1;
		}
		j++;
		sum+=p[k]+a-minn;
		k++;
	}	
	printf("%d",sum+minn);
	return 0;
}
