#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,x,a,i,b,c;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>x;
	i=0;
	for(a=1;a<=n;a++){
		if(a-x==0) i=i+1;
	}
	if(x*11<n) i=i+2;
	if(x*111<n) i=i+3;
	if(x*1111<n) i=i+4;
	if(x*11111<n) i=i+5;
	if(x*111111<n) i=i+6;
	cout<<i;
	return 0;
}
