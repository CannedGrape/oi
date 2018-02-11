#include <stdio.h>
int n, temp, last, ans;

int main() {
	int i;
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	scanf("%d%d", &n, &ans);
	last = ans;
	for (i = 1; i < n; i++) {
		scanf("%d", &temp);
		if (temp > last) 
			ans += (temp - last);
		last = temp;
	}
	printf("%d\n", ans);
	return 0;
}
