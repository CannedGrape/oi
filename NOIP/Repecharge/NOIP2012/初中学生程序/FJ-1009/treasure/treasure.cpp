#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	int n,m,f,next,b,f2,total=0;
	scanf("%d",&n);
	scanf("%d",&m);
	int x[n][m];
	bool s[n][m];			//stairs
	for (f=0;f<n;f++){
		memset(s[f],true,m);
		for (f2=0;f2<m;f2++){
			scanf("%d",&b);
			if (b==0) s[f][f2]=false;
			scanf("%d",&x[f][f2]);
		}
	}
	scanf("%d",&next);
	for (f=0;f<n;f++){
		total=total+x[f][next];
		if (total>=20123000) total=total%20123;
		for (f2=x[f][next];f2>0;next++){
			if (next==m) next=0;
			if (s[f][next]) f2--;
		}
		if (next==0) next=m-1;
		else next--;
	}
	printf("%d",total%20123);
	return 0;
}