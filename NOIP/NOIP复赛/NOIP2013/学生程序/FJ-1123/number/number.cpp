#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int i,j,k,l,m,n,p,ma,a[1000005],b[1000005],c[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a)); memset(b,0,sizeof(b)); memset(c,0,sizeof(c));
	cin>>n>>p;
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	b[1]=a[1]; c[1]=a[1];
	for (i=2; i<=n; i++){
	  if (a[i]+b[i-1]<=b[i-1]) b[i]=b[i-1]%p;
	  else b[i]=(a[i]+b[i-1])%p;
	  
	  if (b[i-1]+c[i-1]<=c[i-1]) c[i]=c[i-1];
	  else c[i]=(b[i-1]+c[i-1])%p;
	}
	cout<<c[n]%p<<endl;
	return 0;
}
