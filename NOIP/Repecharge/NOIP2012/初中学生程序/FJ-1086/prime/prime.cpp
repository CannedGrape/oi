#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	long long x,i;
	scanf("%I64d",&x);
	if(x%2==0){
		printf("%I64d",x/2);
		goto abc;
	}
	else{
		i=x-2;
	}
	for(;i>=2;i-=2){
		if(x%i==0){
			printf("%I64d",i);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	abc:
	return 0;
}
	

	
