#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int m[1000000],t[1000000],s[1000000];
int n,p,a[1000000],i,sm=0,st=0,ss=0,big;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>n>>p;
  cin>>m[1];
  t[1]=m[1];
  s[1]=m[1];
  st=m[1];
  ss=t[1]+s[1];
  big=s[1];
  for(i=2;i<=n;i++)
    {
	  cin>>m[i];
	  if(m[i]>0)st+=m[i];
	  t[i]=st;
	  if(t[i-1]+s[i-1]>ss)ss=t[i-1]+s[i-1];
	  s[i]=ss;
	  if(s[i]>big)big=s[i];
	}
  if(big>0)cout<<big%p<<endl;else cout<<'-'<<abs(big)%p<<endl;
  return 0;
}
