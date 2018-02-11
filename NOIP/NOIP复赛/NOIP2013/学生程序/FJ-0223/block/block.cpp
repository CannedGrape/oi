//rp++
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdlib>
using namespace std;
int i,j,n,m,l,ans,k;
int a[100100],b[100100],c[100100];
bool f[100100];
int ma(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int mi(int a,int b)
{
	if(a<b) return a;
	else return b;
}
void qs(int l,int r)
{
	int i=l,j=r,x=b[(l+r)/2];
	do
	{
		while(b[i]<x) i++;
		while(b[j]>x) j--;
		if(i<=j)
		{
			swap(c[i],c[j]);
			swap(b[i],b[j]);
			i++;j--;
		}
	}while(i<=j);
	if(i<r) qs(i,r);
	if(l<j) qs(l,j);
}
int work(int l,int r,int x)
{
	int i,k;
	k=0;
	for(i=x;i<=n;i++)
	{
		if(l==r) 
		{
			if(f[l]==false) 
			{
				return 0;
			}
			else 
			{
				f[l]=false;
				return a[l];
			}
		}
		if(c[i]<=r&&c[i]>=l)
		{
			if(c[i]==l) 
			{
				l++;
				continue;
			}
			else
			{
			  if(c[i]==r)
			  {
				  r--;
				  continue;
			  }
			  else
			  {
					k+=work(l,c[i]-1,i+1);
					k+=work(c[i]+1,r,i+1);
					k-=a[c[i]];
					return k;
			  }
			}	
		}
	}	
	return k;
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	memset(f,true,sizeof(f));
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		c[i]=i;
	}
	
	qs(1,n);
	cout<<work(1,n,1)<<endl;
	return 0;
}


