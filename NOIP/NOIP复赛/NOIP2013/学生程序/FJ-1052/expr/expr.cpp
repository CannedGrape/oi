#include <iostream>
#include <stdio.h>
using namespace std;
short mult(short a,short b){
	return (a*b)%10000;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int sum=0,a,b;
	char symb='+';
	while (symb=='+'){
		scanf("%d",&a);
		scanf("%c",&symb);
		while (symb=='*'){
			scanf("%d",&b);
			a=mult((a%10000),(b%10000));
			scanf("%c",&symb);
		}
		sum=(sum+a)%10000;
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}