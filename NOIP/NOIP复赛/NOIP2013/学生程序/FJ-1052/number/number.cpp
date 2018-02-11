#include <iostream>
#include <stdio.h>
using namespace std;
int compare(int a,int b){
	if (a>b) return a;
	else return b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,p,num,s,point,maxsum=0,maxp,maxps,f;
	scanf("%d %d",&n,&p);
	scanf("%d",&s);
	maxps=maxp=point=s;
	if (s>0) maxsum=s;
	for (f=1;f<n;f++){
		scanf("%d",&num);
		point=compare(maxps,point+s);
		if (maxp<point) maxp=point;
		s=compare(s,maxsum+n);
		maxsum=maxsum+s;
		if (point+s>maxps) maxps=point+s;
		if (maxsum<0) maxsum=0;
	}
	printf("%d",maxp%p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}