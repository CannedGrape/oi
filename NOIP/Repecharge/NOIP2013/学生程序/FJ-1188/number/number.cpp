#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[1000002],tz[1000002],fs[1000002];
int main()
{
  int n,p,i,j,k,dzd,zd=-2000000004;
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>n>>p;
  for(i=1;i<=n;i++)cin>>a[i];
  for(i=1;i<=n;i++)
  {
     tz[i]=-1000000002;
	 for(j=1;j<=i;j++)
     {
	   dzd=0;
	   for(k=j;k<=i;k++)
	   {
	     dzd+=a[k];
	     if (tz[i]<dzd)tz[i]=dzd;    
	   }
	 } 
	 if(i==1)fs[i]=tz[i];
	 else 
	 {
	    fs[i]=fs[1]+tz[1];
	    for(j=1;j<i;j++)if(fs[j]+tz[j]>fs[i])fs[i]=fs[j]+tz[j];
	 }
     if(zd<fs[i])zd=fs[i];
  }
  if(zd>=0)cout<<zd%p<<endl;
  else cout<<"-"<<abs(zd)%p<<endl;
  return 0;
}

