#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <cstdlib>
using namespace std;
int f[1000001],a[1000001],g[1000001],n;
int low(int a,int b)
{
	if(a>b) return b;
	else return a;
}
int hign(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	if(n==1) {
	cout<<1<<endl;return 0;}
	for(int i=1;i<=n;i++)
	 {
	 for(int j=1;j<i;j++)
	  {
			if(f[j]%2==0&&a[i]<g[j]) 
			{
			 if(f[j]+1>f[i])
			 {f[i]=f[j]+1;
			 g[i]=a[i];}
			 if(f[j]+1==f[i])
			 {
             g[i]=a[i];
			 }
			}
			if(f[j]%2==1&&a[i]>g[j])
			{
			 if(f[j]+1>f[i])
			 {f[i]=f[j]+1;
			 g[i]=a[i];}
			 if(f[j]+1==f[i])
			 g[i]=hign(a[i],g[i]);
			} 
	  }		
	if(f[i-1]>f[i])
	{
	 f[i]=f[i-1];
	 g[i]=g[i-1];
	}
	 }	
	int max1=f[n];
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
	 {
	 for(int j=1;j<i;j++)
	  {
			if(f[j]%2==0&&a[i]>g[j]) 
			{
			 if(f[j]+1>f[i])
			 {f[i]=f[j]+1;
			 g[i]=a[i];}
			 if(f[j]+1==f[i])
			 g[i]=hign(a[i],g[i]);
			}
			if(f[j]%2==1&&a[i]<g[j])
			{
			 	if(f[j]+1>f[i])
			 {f[i]=f[j]+1;
			 g[i]=a[i];}
			 if(f[j]+1==f[i])
			 {
				g[i]=a[i];
			 }
			}
	  }		
	 	if(f[i-1]>f[i])
	{
	 f[i]=f[i-1];
	 g[i]=g[i-1];
	}
	 }
	if(max1>f[n]) cout<<max1<<endl;
	else cout<<f[n]<<endl;
	return 0;
}
