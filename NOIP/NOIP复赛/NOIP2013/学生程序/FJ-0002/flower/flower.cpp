#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 100000 + 50;
const bool UP = true;
const bool DOWN = false;

int a[maxn] = {0};
int n;
int ans = 0;

int main()
{
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	if (n == 1)
	{
		puts("1");
		return 0;
	}
	ans = 2;
	bool CurrentDirection = a[1] < a[2];
	for (int i = 3; i <= n; i++)
	{
		if (CurrentDirection)
		{
			if (a[i] < a[i - 1])
			{
				CurrentDirection = DOWN;
				ans++;
				continue;
			}
		}
		else
		{
			if (a[i] > a[i - 1])
			{
				CurrentDirection = UP;
				ans++;
				continue;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
 
