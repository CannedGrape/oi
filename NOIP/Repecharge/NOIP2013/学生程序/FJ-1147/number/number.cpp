#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,p,a[1005],tz[1005],fs[1005],i,j,t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	for(i=1;i<=n;i++)
	  cin>>a[i];
	for(i=1;i<=n;i++)
	  for(j=1;j<=i;j++)
	    tz[i]+=a[j];
	fs[1]=tz[1];
	for(i=2;i<=n;i++)
	  {
	   for(j=1;j<i;j++)
	     if(fs[j]+tz[j]>t)
		   t=fs[j]+tz[j];
	   fs[i]=t;
	   t=0;
	  }
	t=0;
	for(i=1;i<=n;i++)
	  if(fs[i]>t) t=fs[i];
	t=t%p;
	cout<<t<<endl;
	return 0;
} 

