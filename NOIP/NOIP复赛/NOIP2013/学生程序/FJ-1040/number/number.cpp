# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <math.h>
# include <algorithm>
using namespace std;

int n,mod;
int a[1000010];
long long b[1000010];
long long mark[1000010];
long long s[1000010];

long long max(long long a,long long b) {
	return a > b ? a : b;
}

int main() {
	//score 20-50
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%d %d",&n,&mod);
	for (int i = 1; i <= n; ++i) {
		//WINDOWS
		//scanf("%I64d",&a[i]);
		//LINUX
		scanf("%d",&a[i]);
	}
	
	for (int i = 1; i <= n; ++i) {
		long long sum = 0, maxx = -2147483647;
		for (int j = 1; j <= i; ++j) {
			sum += a[j];
			maxx = max(maxx, sum);
			if (sum < 0) sum = 0;
		}
		b[i] = maxx;
	}
	
	long long ans;
	mark[1] = b[1];
	ans = mark[1];
	
	for (int i = 2; i <= n; ++i) {
		long long maxc = -2147483647;
		for (int j = 1; j < i; ++j)
			maxc = max(maxc, b[j] + mark[j]);
		mark[i] = maxc;
		ans = max(ans, mark[i]);
	}
	
	int sign = 1;
	if (ans < 0) sign = -1;
	ans = (ans < 0) ? (-1 * ans) : ans;
	ans %= mod;
	ans *= sign;
	//WINDOWS
	//printf("%I64d\n",ans % mod);
	//LINUX
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
