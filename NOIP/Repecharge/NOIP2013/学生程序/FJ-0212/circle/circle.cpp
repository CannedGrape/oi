#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

#define MAXN 1000050

int visited[MAXN];

int mod(int k, int t)
{
	int sum = 1;
	
	for (int i=1; i<=k; i++)
	{
		sum = sum * 10;
		if (sum >= t)
			sum = sum % t;
	}
	return sum;
}

int main() {
	int n, m, k, x;
	int x0;
	int t;
	int left;
	
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &k, &x);	
	x0 = x;
	
	for (int i=1; ; i++)
	{
		x = (x + m ) % n;
		if (x == x0 || visited[x] != 0)
		{
			t = i - visited[x];
			
			left = mod(k, t) - i % t;
			if (left < 0)
				left += t;
			for (int j=1; j<=left; j++)
				x = (x + m) % n;
			printf("%d\n", x);
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		visited[x] = i;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
