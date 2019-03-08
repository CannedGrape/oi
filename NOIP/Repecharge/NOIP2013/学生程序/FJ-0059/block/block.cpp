#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?(-(a)):(a))
#define sqr(a) a*a
#define swap(a,b) a^=b;b^=a;a^=b;
#define S 10000
#define MAX 2139062143
#define N 100004
#define M 300004
using namespace std;
int n,ans;
int h[N];
int t[M],mint[M],mark[M],sum[M],num[M];
void build(int l,int r,int k,int a,int x)
{
	if(l>r)return;
	if(l>a || a>r)return;
	if(l==r)
	{
		t[k]=x;
		mint[k]=x;
		num[k]=l;
		return;
	}
	int m=(l+r)>>1;
	build(l,m,k<<1,a,x);
	build(m+1,r,(k<<1)+1,a,x);
	mint[k]=min(mint[k<<1],mint[(k<<1)+1]);
	num[k]=mint[k<<1]<mint[(k<<1)+1]?num[k<<1]:num[(k<<1)+1];
}
void change(int l,int r,int k,int a,int b,int x)
{
	if(l>r)return;
	if(b<l || a>r)return;
	if(l==r)
	{
		t[k]-=sum[k]+x;
		//if(t[k]==0)t[k]=MAX;
		mint[k]=t[k];
		sum[k]=0;
		mark[k]=0;
		return;
	}
	if(a<=l && r<=b)
	{
		sum[k]+=x;
		mint[k]-=x;
		mark[k]=1;
		return;
	}
	if(mark[k])
	{
		mark[k<<1]=mark[(k<<1)+1]=1;
		mark[k]=0;
		sum[k<<1]+=sum[k];sum[(k<<1)+1]+=sum[k];
		sum[k]=0;
	}
	int m=(l+r)>>1;
	change(l,m,k<<1,a,b,x);
	change(m+1,r,(k<<1)+1,a,b,x);
	mint[k]=min(mint[k<<1],mint[(k<<1)+1]);
	num[k]=mint[k<<1]<mint[(k<<1)+1]?num[k<<1]:num[(k<<1)+1];
}
int findmin(int l,int r,int k,int a,int b)
{
	if(l>r)return MAX;
	if(b<l || a>r)return MAX;
	if(l==r)
	{
		return mint[k]-sum[k];
	}
	if(a<=l && r<=b)
	{
		return mint[k]-sum[k];
	}
	if(mark[k])
	{
		mark[k]=0;
		mark[k<<1]=mark[(k<<1)+1]=1;
		sum[k<<1]+=sum[k];sum[(k<<1)+1]+=sum[k];
		sum[k]=0;
	}
	int m=(l+r)>>1;
	int x1=findmin(l,m,k<<1,a,b);
	int x2=findmin(m+1,r,(k<<1)+1,a,b);
	return min(x1,x2);
}
int findnum(int l,int r,int k,int a,int b,int x)
{
	if(l>r)return 0;
	if(b<l || a>r)return 0;
	if(l==r)
	{
		return num[k];
	}
	if(mint[k]==x)return num[k];
	int m=(l+r)>>1;
	int x1=findnum(l,m,k<<1,a,b,x);
	int x2=findnum(m+1,r,(k<<1)+1,a,b,x);
	if(x1!=0)return x1;
	return x2;
}
void work(int l,int r)
{
	int x,k;
	if(l>r)return;
	x=findmin(1,n,1,l,r);
	if(x==MAX)return;
	k=findnum(1,n,1,l,r,x);
	ans+=x;
	if(k==0)return;
	change(1,n,1,l,r,x);
	work(l,k-1);
	work(k+1,r);
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		build(1,n,1,i,h[i]);
	}
	work(1,n);
	cout<<ans<<endl;
	return 0;
}
