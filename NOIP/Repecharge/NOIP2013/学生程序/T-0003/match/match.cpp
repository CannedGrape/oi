#include<iostream>
#include<cmath>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100003],b[100003];
int a1[100003],b1[100003];
int a2[100003],b2[100003];
int f[4][100003],g[4][100003];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,sum1=0,sum2=0,sum3=0;
	int i,j,k,check=0,t,minn;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
		a1[i]=a2[i]=a[i];	
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);		
		b1[i]=b2[i]=b[i];
	}
	for(j=1;j<=n;j++)
	{
		f[1][j]=a[j]-b[j]+a[j-1]-b[j-1];
	}
	
	for(j=3;j<=n;j++)
	{
		for(i=2;i<=3;i++)
		{
			if(g[i][j-1]>g[i-1][j-1]) 
			{
				g[1][j]=a[j]-b[j]+g[i-1][j-1];sum1++;
				a1[j]=t;a1[j]=a1[j+1];a1[j+1]=t;
				g[2][j]=a1[j]-b1[j]+g[i-1][j-1];sum2+=2;
				a2[j]=t;a2[j]=a2[j+1];a2[j+1]=t;
				g[2][j]=a2[j]-b2[j]+g[i-1][j-1];sum3+=2;
			}
			
		}
		
	}
	if(sum1<sum2) minn=sum1;
	else minn=sum2;
	if(sum3<minn) minn=sum3;

	cout<<minn;
	return 0;
}
