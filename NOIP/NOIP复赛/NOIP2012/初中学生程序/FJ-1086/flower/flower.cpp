#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[101],x[101],k;
long long y=0,z;
int dg(int b){
	if(b<n){
		for(int i=0;i<=a[b];i++){
			x[b]=i;
			k=0;
			for(int j=1;j<=b;j++){
				k+=x[j];
			}
			if(k>m){
				return 0;
			}
			dg(b+1);
		}
	}
	else{
		k=0;
		for(int i=1;i<=n-1;i++){
			k+=x[i];
		}
		if(k+a[n]>=m){
			y++;
		}
	}
	return 0;
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//sort(a+1,a+n);
	for(int i=0;i<=100;i++){
		x[i]=0;
	}
	dg(1);
	z=y%1000007;
	printf("%I64d",z);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
