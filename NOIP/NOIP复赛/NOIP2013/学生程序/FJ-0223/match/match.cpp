//rp++
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;
int i,j,n,m,k,l;
int a[100010],b[100010],c[100010],d[100010],e[100010];
long long ans,ma;
bool flag;
void qs(int l,int r)
{
	int i=l,j=r,x=c[(l+r)/2];
	do{
		while(c[i]<x) i++;
		while(c[j]>x) j--;
		if(i<=j)
		{
			swap(c[i],c[j]);
			swap(d[i],d[j]);
			i++;j--;
		}
	}while(i<=j);
	if(i<r) qs(i,r);
	if(l<j) qs(l,j);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
		d[i]=i;
	}
	qs(1,n);
	for(i=1;i<=n;i++) 
	{
		a[d[i]]=i;
		e[i]=d[i];
    }
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		c[i]=b[i];
		d[i]=i;
	}
	qs(1,n);
	for(i=1;i<=n;i++) 
	{
		b[d[i]]=i;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==b[i+1]&&b[i]==a[i+1]) 
		{
			swap(a[i],a[i+1]);
			swap(e[a[i]],e[a[i+1]]);
			ans++;
		}
	}
	ma=1;flag=false;
	for(i=1;i<=n;i++)
	{
		c[i]=e[i]-d[i];
		if(c[i]<0) c[i]=-c[i];
		if(c[i]!=0)
		{
			ma+=c[i];
			ma--;
			flag=true;
		}
	}
	if(flag==false) ma--;
	cout<<ans+ma<<endl;
	return 0;
}
