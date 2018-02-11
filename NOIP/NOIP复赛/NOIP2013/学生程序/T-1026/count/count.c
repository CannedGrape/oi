#include<stdio.h>
#include<stdlib.h>

int n = 0, x = 0, k = 0, temp = 0, counter = 0;
	
int main(void){
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	scanf("%d%d", &n, &x);
	for(k = 1; k <= n; k++){
		if(k == 1000000 && x == 1){
			counter++;
		}
		if(k >= 100000 && k / 100000 % 10 == x){
			counter++;
		}
		if(k >= 10000 && k / 10000 % 10 == x){
			counter++;
		}
		if(k >= 1000 && k / 1000 % 10 == x){
			counter++;
		}
		if(k >= 100 && k / 100 % 10 == x){
			counter++;
		}
		if(k >= 10 && k / 10 == x){
			counter++;
		}
		if(k % 10 == x){
			counter++;
		}
	}
	printf("%d", counter);
	return 0;
}

