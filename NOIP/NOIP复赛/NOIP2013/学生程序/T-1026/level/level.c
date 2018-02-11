#include<stdio.h>
#include<stdlib.h>

int main(void){
	int n = 0, m = 0, k = 0, t = 0;
	freopen("level.in", "r", stdin);
	freopen("level.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(k = 0; k < m; k++){
		scanf("%d", &t);
		for(k = 0; k < t; k++){
			scanf("%d", &t);
		}
	}
	printf("%d", m);
	return 0;
} 
