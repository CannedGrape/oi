#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
	freopen("expt.in","r",stdin);
	freopen("expt.out","w",stdout);
	char a[1000000];
	cin.getline(a,1000000);
	int i,b,c[1000000],d=0;
	for(b=0;a[b]!='0';b++);
	for(i=0;i<=b;i++){
		if(a[i]!='+'&&a[i]!='*'){
			if(a[i]=='1') c[i]==1;
			if(a[i]=='2') c[i]==2;
			if(a[i]=='3') c[i]==3;
			if(a[i]=='4') c[i]==4;
			if(a[i]=='5') c[i]==5;
			if(a[i]=='6') c[i]==6;
			if(a[i]=='7') c[i]==7;
			if(a[i]=='8') c[i]==8;
			if(a[i]=='9') c[i]==9;
			if(a[i]=='0') c[i]==0;
			d=10*d+c[i];
		}
		if(a[i-1]=='+') d=
	}
	return 0;
}
