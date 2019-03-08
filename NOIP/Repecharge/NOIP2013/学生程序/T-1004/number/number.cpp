#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,p,a[1000],b[1000],i,j,c[1000],d,x=0,y=0;
	cin>>n>>p;
	for(i=0;i<=n;i++){
		cin>>a[i];
	}
	b[0]=a[0];
	j=a[0];
	for(i=0;i<n;i++){
		if(i!=0) b[i]=y;
		x=0;
		for(d=0;d<=i;d++){
			if(b[d]>j) j=b[d];
			x=x+b[d];
			if(x>j) j=x;
			b[i]=j;
			if(i+1<=n) y=j;
		}
	}
	c[0]=b[0];
	for(i=0,j=b[0];i<n;i++){
		for(d=0;d<i;d++){ 
			if(b[d]+c[d]>j) j=b[i]+c[i];
			c[d]=j;
		}
	}
	for(i=0,j=0;i<n;i++) if(b[i]+c[i]>j) j=b[i]+c[i];
	if(j>p) j=j-p;
	cout<<j;
	return 0;
}
