#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int n,x,i,ans,a,b;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
    cin>>n>>x;
	i=0;
	a=0;
	b=0;
	ans=0;
	for (i=1;i<=n;i++){
	  a=i;		
	  while (a>0){
	    b=a%10;
	    if (b==x) {ans++;}
	    a=a/10;
	  }	 
	}		
		
	cout<<ans;
	return 0;
}
