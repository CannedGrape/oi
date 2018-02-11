#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
char s[1000000];
int js[1000000],jl[1000000],k,i,j,zjl,j2;
int main()
{
  //freopen("expr.in","r",stdin);
  //freopen("expr.out","w",stdout);
  gets(s);
  for(i=0;i<strlen(s);i++)
   {
    if(s[i]=='+' || s[i]=='*')
	 {
	  for(j2=i-4;j2<i;j2++)
	   {
		if(j2>=0 && s[j2]!='+' && s[j2]!='*')
		 js[j]=js[j]*10+s[j2]-48;
		if(j2<0 || s[j2]=='+' || s[j2]=='*')js[j]=0;
       }
	 }
    if(s[i]=='+')jl[k]=1,k++,j++;
    if(s[i]=='*')jl[k]=2,k++,j++;
   }
  for(j2=i-4;j2<i;j2++) 
   {
	if(j2>=0 && s[j2]!='+' && s[j2]!='*')
	 js[j]=js[j]*10+s[j2]-48;
	if(j2<0 || s[j2]=='+' || s[j2]=='*')js[j]=0;
   }
  for(i=0;i<k;i++)
   {
    if(jl[i]==2)
	 {
	  js[i]*=js[i+1];
	  for(j=i+1;j<=k;j++)js[j]=js[j+1];
	  for(j=i;j<=k;j++)jl[j]=jl[j+1];
	 }
   }
  for(i=0;i<=k;i++)zjl+=js[i];
  cout<<zjl%10000<<endl;
}
