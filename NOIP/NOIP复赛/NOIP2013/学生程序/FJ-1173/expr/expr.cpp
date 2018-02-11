#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdlib>
using namespace std;
string s,k;
int i,l,j,a[1001],c[1001],b[1001],z,r,d,f;
main()
{
  freopen("expr.in","r",stdin);
  freopen("expr.out","w",stdout);
  cin>>s;
  l=s.length();
  i=0;r=0;
  while(i<l)
  {
	z=0;
	k.clear();
    while((s[i]!='+')&&(s[i]!='*')&&(i<l)) 
    {	
	  k=k+s[i];	
	  i++;
    }
    d=k.length();
    if(d>3)z=1000*(int(k[d-4])-48)+100*(int(k[d-3])-48)+10*(int(k[d-2]-48))+int(k[d-1])-48;
    if(d==3)z=100*(int(k[d-3])-48)+10*(int(k[d-2])-48)+int(k[d-1])-48;
    if(d==2)z=10*(int(k[d-2])-48)+int(k[d-1])-48;
    if(d==1)z=int(k[d-1])-48;
	r=r+1;
	a[r]=z;
	if(f==2)
	{a[r-1]=(a[r]*a[r-1])%10000;a[r]=0;r--;}
	f=0;
	if(s[i]=='*'){f=2;}
	i++;
  }
  z=0;
  for(i=1;i<=r;i++)
  {
    z=(z+a[i])%10000;		
  }
  cout<<z<<endl;
  return 0;	
}
