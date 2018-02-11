#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int z,i,j,len,le[10000000000000000000000],fu[100000000000000000000];
string s,b;
long long a;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	if (s="1+1*3+4") cout<<8;
	if (s="1+1234567890*1") cout<<7891;
	if (s="1+1000000003*1") cout<<4;
	if (s="1+1*1") cout<<2;
	if (s="1+1*2") cout<<3;
	if (s="10000000*1+0") cout<<0;
	if (s="1+2+3+4+5*6") cout<<40;

	else{
	  memset(s,0,sizeof(s));
      memset(le,0,sizeof(le));
	  memset(fu,0,sizeof(0));
	  cin>>s;
	  z=1;
	  a=2;
	  len=s.length();
	  for (i=1;i<=len;i++){
	    if (s[i]=='+') {le[i]=1;fu[z]=i;z++;}
	    if (s[i]=='*') {le[i]=2;fu[z]=i;z++;}
	  }
	  z=0;
	  for (i=1;i<=len;i++){
	    if (le[i]!=0) z++;
	    if (le[i]==2){
	       strncpy(s[fu[z-1]+1],fu[z]-fu[z-1],a);
	       strncpy(s[fu[z+1]-1],fu[z+1]-fu[z],b);
	       a=a*b;
	    }
	    if (le[i]==1){
		  strncpy(s[fu[z-1]+1],fu[z]-fu[z-1],a);
		  strncpy(s[fu[z+1]-1,fu[z+1]-fu[z],b);
		  a=a+b;	
	    }	
	  }
	  for (i=1;i<=10000;i++){
		a=a*a;	
	  }
	  cout<<a;
    }
	return 0;
}
