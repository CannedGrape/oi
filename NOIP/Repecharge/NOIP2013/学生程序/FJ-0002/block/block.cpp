#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 50;

int a[maxn] = {0};
int Pq[maxn] = {0};
int last = 0;
int n;
int ans = 0;

int main()
{
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == Pq[last])
			continue;
		if (a[i] > Pq[last])
		{
			ans += a[i] - Pq[last];
			Pq[++last] = a[i];
		}
		else
		{
			while (Pq[last] > a[i])
			{
				last--;
			}
			Pq[++last] = a[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
