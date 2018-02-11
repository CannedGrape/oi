#include <stdio.h>
#include <string.h>
int n, h[100010], f[100010][2];
int ans, maxx;

int max(int a, int b) {
	return a > b ? a : b;	
}

int main() {
	int i, j, k;
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	memset(f, -1, sizeof(f));
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &h[i]);	
	}
	for (i = 1; i <= n; i++) {
		maxx = 0;
		for (j = 1; j < i; j++) {
			if (h[i] < h[j] && f[j][1] > maxx)
				maxx = f[j][1];	
		}
		f[i][0] = max(maxx + 1, 1);
		maxx = -2;
		for (j = 1; j < i; j++) {
			if (h[i] > h[j] && f[j][0] > maxx) 
				maxx = f[j][0];	
		}
		f[i][1] = max(maxx + 1, -1);
	}
/*	for (i =1; i <= n; i++) {
		printf("%d %d\n", f[i][0], f[i][1]);
	}
	printf("\n");*/
	for (i = 1; i <= n; i++) {
		if (f[i][0] > ans) ans = f[i][0];
		if (f[i][1] > ans) ans = f[i][1];	
	}
	memset(f, -1, sizeof(f));
	for (i = 1; i <= n; i++) {
		maxx = 0;
		for (j = 1; j < i; j++) {
			if (h[i] > h[j] && f[j][1] > maxx)
				maxx = f[j][1];	
		}
		f[i][0] = max(maxx + 1, 1);
		maxx = -2;
		for (j = 1; j < i; j++) {
			if (h[i] < h[j] && f[j][0] > maxx) 
				maxx = f[j][0];	
		}
		f[i][1] = max(maxx + 1, -1);
	}
	/*for (i =1; i <= n; i++) {
		printf("%d %d\n", f[i][0], f[i][1]);
	}
	printf("\n");*/
	for (i = 1; i <= n; i++) {
		if (f[i][0] > ans) ans = f[i][0];
		if (f[i][1] > ans) ans = f[i][1];	
	}
	printf("%d\n", ans);
	return 0;
}
