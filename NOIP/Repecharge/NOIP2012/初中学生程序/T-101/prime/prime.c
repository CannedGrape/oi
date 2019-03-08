#include <stdio.h>
#include <math.h>
long sqr(long n) {
	long i;
	i=0;
	while((i*i)<=n) i++;
	//printf("%ld",i);
	return i;
}
long is_prime(long n) {
	long i,t;
	t=sqr(n);
	for(i=2;i<=t;i++) {
		if(n%i==0) return 0;
	}
	return 1;
}
int main() {
	long n,i,j,t;
	long flag,p=0;
	long a[4000];
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	scanf("%ld",&n);
	//printf("%d",sqr(n)+1);
	//for(i=1;i<=n;i++) {
//		//printf("%d\n",i);
//		flag=0;
//		a[i]=0;
//		t=sqr(i)+1;
//		for(j=2;j<=t;j++) {
//			if(i%j==0) {
//				flag=1;
//				break;
//			}
//		}
//		if(flag==0) a[i]=1;
//	}
	
	//for(i=0;i<=n;i++) {
//		printf("%d\n",a[i]);
//	}




	t=sqr(n);
	//------------------------------
	for(i=n;i>=t;i--) {
		//printf("i=%d\n",i);
		if(n%i==0) {
			//printf("n=%d,i=%d,n/i==%d\n",n,i,n/i);
			if(is_prime(i)==1 && is_prime(n/i))	{
				//printf("n=%d,i=%d,n/i==%d\n",n,i,n/i);
				printf("%ld\n",i);
				break;
			}
		}
	}

	return 0;
}
