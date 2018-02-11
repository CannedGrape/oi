#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int i,j,k,m,n,l,p,c[100005],w,we,ans;
long long a[100005],o;
char b[100005]; 
string s,r;

int main(){
  freopen("expr.in","r",stdin);
  freopen("expr.out","w",stdout);
  
  getline(cin,s); n=s.size();
  l=0; k=0; p=0; w=1; ans=0;
  for (i=0; i<=n-1; i++) 
	if (((int)s[i]>=48) && ((int)s[i]<=57)) {
	  r[w]=s[i]; w++;}
	else {
	  we=1; l++;
	  for (j=w-1; j>=1; j--){a[l]+=((int)r[j]-48)*we; we=we*10;}
	  w=1;	
	  k++; b[k]=s[i];
	  if (s[i]=='*') {p++; c[p]=k;}
    }
  l++; we=1;
  for (j=w-1; j>=1; j--){a[l]+=((int)r[j]-48)*we; we=we*10;}

  
  for (j=p; j>=1; j--) {o=a[c[j]]*a[c[j]+1]; a[c[j]]=o%10000;}

  for (j=1; j<=k; j++){
	if ((b[j]=='+') && (b[j-1]=='*') && (j!=1)) {
	  i=j-1; 
	  while ((a[i]=='*') && (i>=1)) i--; ans+=a[i];	
	}
	if (b[j]=='+' && b[j-1]!='*') ans+=a[j]; 
  }
  
  if (b[k]=='+') ans+=a[k+1];
  else {i=k; while ((b[i]=='*') && (i>=1)) i--; ans+=a[i+1];}
  cout<<ans<<endl;
  return 0;	
}
