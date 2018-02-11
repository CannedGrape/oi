#include <stdio.h>
#include <stdlib.h>
#define MOD 99999997
int n, haha[100010], c[100010], d[100010], anss;

struct HEHE{
	int num;
	int pos;	
}a[100010], b[100010];

int cmp1(const void * i, const void * j) {
	struct HEHE * c = (struct HEHE *)i;
	struct HEHE * d = (struct HEHE *)j;
	return c -> num > d -> num;	
}

int cmp2(const void * i, const void * j) {
	struct HEHE * c = (struct HEHE *)i;
	struct HEHE * d = (struct HEHE *)j;
	return c -> pos > d -> pos;	
}

int LIS() {
	int i, l, r, mid, ans = 0;
	for (i = 1; i <= n; i++) {
		l = 1;
		r = ans + 1;
		while (l < r) {
			mid = (l + r) / 2;
			if (haha[mid] > c[i]) r = mid;
			else l = mid + 1;	
		}	
		haha[l] = c[i];
		if (l > ans) ans = l;
	}	
	return ans;
}

int main() {
	int i, j, k, temp;
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d", &n);
	/*for (i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	printf("%d\n", LIS());*/
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i].num);
		a[i].pos = i;	
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &b[i].num);
		b[i].pos = i;	
	}
	qsort(a + 1, n, sizeof(struct HEHE), cmp1);
	qsort(b + 1, n, sizeof(struct HEHE), cmp1);
	for (i = 1; i <= n; i++) {
		a[i].num = b[i].num = i;	
	}
	qsort(a + 1, n, sizeof(struct HEHE), cmp2);
	qsort(b + 1, n, sizeof(struct HEHE), cmp2);
	/*for (i = 1; i <= n; i++) {
		printf("%d %d\n", a[i].num, b[i].num);	
	}*/
	for (i = 1; i <= n; i++) {
		if (a[i].num == b[i].num) continue;
		//printf("%d \n", i);
		for (j = i + 1; j <= n; j++) {
			if (b[j].num == a[i].num) {
				temp = b[j].num;
				for (k = j; k > i; k--) {
					b[k].num = b[k-1].num;	
				} 
				anss = (anss + j - i) % MOD;
				b[i].num = temp;
				break;	
			}
		}	
	}	
	printf("%d\n", anss % MOD);
	/*for (i = 1; i <= n; i++) {
		//a[i].num = b[i].num = i;
		//printf("%d %d\n", a[i].pos, b[i].pos);
		//d[a[i]] = i;	
	}
	for (i = 1; i <= n; i++) {
		
	}
	printf("%d\n", n - LIS());*/
	//system("PAUSE");
	return 0;
}

