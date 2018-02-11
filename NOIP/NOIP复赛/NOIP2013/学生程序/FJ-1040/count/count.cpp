# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <math.h>
# include <algorithm>
using namespace std;

int thedigit (int num,int k) {
	// find k in num, return the number of k
	int ret = 0;
	while (num != 0) {
		if (num % 10 == k) ret++; 
		num = num / 10;
	}
	return ret;
}

int main() {
	//score 100
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	int n, x;
	scanf("%d %d", &n, &x);
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += thedigit(i, x);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
