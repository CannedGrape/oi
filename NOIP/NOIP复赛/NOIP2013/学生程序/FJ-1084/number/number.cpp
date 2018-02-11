#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
long long n,p;
long long a[10000],tz[10000]={},ma[10000]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long i,j,minn=2147483647,maxx=0,c=0;
	cin>>n>>p;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		if(a[i]<=0) c++;
	}
	if(c==n) {
		for(i=1;i<=n;i++){
			a[i]=-a[i];
			if(a[i]<minn) minn=a[i];
		}
		cout<<-minn%p;
		return 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++) tz[i]+=a[j];
	}
	ma[1]=tz[1];
	maxx=ma[1]+tz[1];
	for(i=2;i<=n;i++){
		ma[i]=max(ma[i-1]+tz[i-1],maxx);
		if(ma[i]==ma[i-1]+tz[i-1]) maxx=ma[i];
	}
	cout<<ma[n]%p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
