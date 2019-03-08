#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?(-(a)):(a))
#define MAX 2139062143
#define S 10000
#define mod 199999994
#define N 100004
using namespace std;
int n,ans;
int a[N],b[N],A[N],B[N],numa[N],numb[N],marka[N],markb[N];
bool cmp(int aa,int bb)
{
	return aa<bb;
}
int findA(int x)
{
	int l=1,r=n,m;
	while(l<r)
	{
		m=(l+r+1)>>1;
		if(A[m]==x)return m;
		if(x<A[m])r=m-1;
		else l=m+1;
	}
	return r;
}
int findB(int x)
{
	int l=1,r=n,m;
	while(l<r)
	{
		m=(l+r+1)>>1;
		if(B[m]==x)return m;
		if(x<B[m])r=m-1;
		else l=m+1;
	}
	return r;
}
void print()
{
	int i;
	for(i=1;i<=n;i++)
		cout<<numa[i]<<" ";
	cout<<endl;
	for(i=1;i<=n;i++)
		cout<<numb[i]<<" ";
	cout<<endl;
	for(i=1;i<=n;i++)
		cout<<marka[i]<<" ";
	cout<<endl;
	for(i=1;i<=n;i++)
		cout<<markb[i]<<" ";
	cout<<endl;
	
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		A[i]=a[i];
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		B[i]=b[i];
	}
	sort(A+1,A+1+n,cmp);
	sort(B+1,B+1+n,cmp);
	for(i=1;i<=n;i++)
	{
		numa[i]=findA(a[i]);
		marka[numa[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		numb[i]=findB(b[i]);
		markb[numb[i]]=i;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=abs(marka[i]-markb[i]);
		while(ans>=mod)ans-=mod;
	}
	ans/=2;
	cout<<ans<<endl;
	return 0;
}
