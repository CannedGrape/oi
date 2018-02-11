#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,m,a[101],fangfa=0;
void tryy(int z,int b){
	int f,f2;
	for (f=z;f<=n;f++){
		if (z==n && b+a[z]>=m) {
		fangfa++;
		if (fangfa>10000000) fangfa=fangfa%1000007;
		return ;
		}
		else {
			for (f2=0;f2<=a[z];f2++){
				if (b+f2==m){
					fangfa++;
					if (fangfa>10000000) fangfa=fangfa%1000007;
					break;
				}
				else (tryy(f+1,b+f2));
			}
		}
	}
	return ;
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int f;
	scanf("%d",&n);
	scanf("%d",&m);
	for (f=1;f<=n;f++) scanf("%d",&a[f]);
	tryy(1,0);
	printf("%d",fangfa%1000007);
	return 0;
}