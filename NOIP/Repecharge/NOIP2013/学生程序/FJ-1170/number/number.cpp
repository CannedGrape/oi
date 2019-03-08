#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
long long a,b,s[10000],i,s2[100000],jl,mx,j,cjl;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>a>>b;
  for(i=0;i<a;i++)cin>>s[i],s2[i]=s[i];
  for(i=1;i<a;i++)
   {
    mx=s[0];
	for(j=0;j<i;j++)if(mx<s[j])mx=s[j];
	if(s[i]+mx>s[i])s[i]=s[i]+mx;
   }
  for(i=1;i<a;i++)
   {
	mx=s[0];
	for(j=0;j<i;j++)if(mx<s[j])mx=s[j],cjl=j;
	s2[i]=s[cjl]+s2[cjl];
   }
  jl=s2[0];
  for(i=0;i<a;i++)if(jl<s2[i])jl=s2[i];
  cout<<jl%b<<endl;
}
