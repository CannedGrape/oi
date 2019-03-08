#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int f[200000][2],i,j,k,l,x,y,m,n,p1,p2;
int a[200000],b1[200000],b2[200000],d1[200000],d2[200000];
int ef1(int l,int r,int c)
{
	if ((b1[1]<=a[c])||(p1==0)) return 0;
	if (r-l==0) return d1[l];
	if (r-l==1){if (b1[r]>a[c]) return d1[r];else return d1[l];}
	int mid=(l+r)/2;
	if (a[c]>=b1[mid]) return ef1(l,mid-1,c);else return ef1(mid,r,c);
}
int ef2(int l,int r,int c)
{
	if ((b2[1]>=a[c])||(p2==0)) return -1;
	if (r-l==0) return d2[l];
	if (r-l==1){if (b2[r]<a[c]) return d2[r];else return d2[l];}
	int mid=(l+r)/2;
	if (a[c]<=b2[mid]) return ef2(l,mid-1,c);else return ef2(mid,r,c);
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;m=0;
	for (i=1;i<=n;i++) cin>>a[i];
	memset(f,0,sizeof(f));
	if  (n<=1000)
	{
		f[1][1]=1;f[1][0]=0;
		for (i=2;i<=n;i++)
		{
			for (j=1;j<i;j++)
			{
				if (a[i]<a[j]) f[i][1]=max(f[j][0]+1,f[i][1]);
				if (a[i]>a[j]) f[i][0]=max(f[j][1]+1,f[i][0]);
			}
			m=max(m,f[i][1]);m=max(m,f[i][0]);
		}
		for (i=1;i<=n;i++) a[i]=-a[i]+1000000;
		memset(f,0,sizeof(f));
		f[1][1]=1;f[1][0]=0;
		for (i=2;i<=n;i++)
		{
			for (j=1;j<i;j++)
			{
				if (a[i]<a[j]) f[i][1]=max(f[j][0]+1,f[i][1]);
				if (a[i]>a[j]) f[i][0]=max(f[j][1]+1,f[i][0]);
			}
			m=max(m,f[i][1]);m=max(m,f[i][0]);
		}
		cout<<m<<endl;
		return 0;
	}
	p1=0;p2=0;
	for (i=1;i<=n;i++)
	{
		x=ef1(1,p1,i);f[i][1]=x+1;
		x=ef2(1,p2,i);f[i][0]=x+1;
		if (f[i][0]>0&&f[i][0]>=d1[p1])
		{  while ((p1>0)&&(b1[p1]<=a[i])) p1--;
		   p1++;b1[p1]=a[i];d1[p1]=f[i][0];
		}
		if (f[i][1]>=d2[p2])
		{
		  while ((p2>0)&&(b2[p2]>=a[i])) p2--;
		  p2++;b2[p2]=a[i];d2[p2]=f[i][1];
		}
		m=max(m,f[i][1]);m=max(m,f[i][0]);
		b1[p1+1]=-1000000000;
		b2[p2+1]=1000000000;
	}
	for (i=1;i<=n;i++) a[i]=-a[i]+1000000;
	memset(f,0,sizeof(f));
	p1=0;p2=0;
	for (i=1;i<=n;i++)
	{
		x=ef1(1,p1,i);f[i][1]=x+1;
		x=ef2(1,p2,i);f[i][0]=x+1;
		if (f[i][0]>0&&f[i][0]>=d1[p1])
		{  while ((p1>0)&&(b1[p1]<=a[i])) p1--;
		   p1++;b1[p1]=a[i];d1[p1]=f[i][0];
		}
		if (f[i][1]>=d2[p2])
		{
		  while ((p2>0)&&(b2[p2]>=a[i])) p2--;
		  p2++;b2[p2]=a[i];d2[p2]=f[i][1];
		}
		m=max(m,f[i][1]);m=max(m,f[i][0]);
		b1[p1+1]=-1000000000;
		b2[p2+1]=1000000000;
	}
	cout<<m<<endl;
	return 0;
}
	
