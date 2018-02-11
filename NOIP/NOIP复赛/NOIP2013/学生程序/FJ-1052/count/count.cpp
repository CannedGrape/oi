#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,n2,x,sum=0,tmp;
	scanf("%d %d",&n,&x);
	for (tmp=1,n2=n;n2>0;tmp=tmp*10,n2=n2/10){
		sum=sum+n2/10*tmp;
		printf("%d:%d %d",tmp,n2/10*tmp,sum);
		if (x==0){
			sum=sum-tmp;
			if (n2%10>x) sum=sum+n%tmp;
		}
		if (n2%10==x){
			sum=sum+n%tmp+1;
		}
		if (n2%10>x && x!=0) sum=sum+(n/tmp+1)*tmp/10;
		printf(" %d\n",sum);
	}
	if (x==0) sum=sum+tmp/10;
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}