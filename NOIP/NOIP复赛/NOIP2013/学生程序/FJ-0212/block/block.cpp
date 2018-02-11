#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

#define MAXN 100050

int n;
int data[MAXN];
long long f[MAXN];

int main() {
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	
	memset(f, 0, sizeof(f));
	data[0] = 0;
		
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &data[i]);
	
	for (int i=1; i<=n; i++)
		if (data[i-1] <= data[i])
			f[i] = f[i-1] + data[i] - data[i-1];
		else
			f[i] = f[i-1];
	printf("%lld\n", f[n]);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

/*
f[i] = {
         data[i-1] <= data[i] -> f[i-1] + data[i] - data[i-1],
         data[i-1] > data[i] -> f[i-1]
}
// maybe wrong?

*/
