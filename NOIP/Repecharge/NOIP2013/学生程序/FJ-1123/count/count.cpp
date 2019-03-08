#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,x,i,j,k,m,ans;

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>x; ans=0; 
	for (i=1; i<=n; i++){
	  m=i;
	  while (m>=1){		
		k=m%10; 
		if (k==x) ans++;
		m=m/10;	
	  }	
	}
	cout<<ans<<endl;
	return 0;
}
