#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
bool pd(int n){
	if (n==2) return true;
	if (n%2==0) return false;
	int f,st=sqrt(n);
	for (f=3;f<=st;f=f+2) if (n%f==0 && f!=n) return false;
	return true;
}
int main(){
	int n,f,st;
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	scanf("%d",&n);
	if (pd(n)) {
		printf("%d",n);
		return 0;
	}
	if (n==4) {
		printf("%d",2);
		return 0;
	}
	st=sqrt(n);
	for (f=3;f<=st;f=f+2){
		if (n%f==0 && pd(f)) {
			n=n/f;
			if (pd(n)) {
			printf("%d",n);
			return 0;
			}
		}
	}
	return 0;
}