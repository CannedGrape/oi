#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

#define MAXN 100050
#define MAXH 1050
#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

// solution for 70

int n;
int data[MAXN];
int f[MAXH][2];

int main() {
	int ans = 1;
	int hmax = 0;
	
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &data[i]);
	
	// case A: 
	memset(f, 0, sizeof(f));
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=hmax; j++)
		{
			if (f[j][0] != 0 && data[i] > j) // curr is oushu
			{
				f[data[i]][1] = MAX(f[data[i]][1], f[j][0] + 1);
				ans = MAX(f[data[i]][1], ans);
			}
			if (f[j][1] != 0 && data[i] < j) // curr is qishu
			{
				f[data[i]][0] = MAX(f[data[i]][0], f[j][1] + 1);
				ans = MAX(f[data[i]][0], ans);
			}
		}
		f[data[i]][0] = MAX(f[data[i]][0], 1);
		hmax = MAX(hmax, data[i]);
	}
	
	// case B
	hmax = 0;
	memset(f, 0, sizeof(f));
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=hmax; j++)
		{
			if (f[j][0] != 0 && data[i] < j) // curr is oushu
			{
				f[data[i]][1] = MAX(f[data[i]][1], f[j][0] + 1);
				ans = MAX(f[data[i]][1], ans);
			}
			if (f[j][1] != 0 && data[i] > j) // curr is qishu
			{
				f[data[i]][0] = MAX(f[data[i]][0], f[j][1] + 1);
				ans = MAX(f[data[i]][0], ans);
			}
		}
		f[data[i]][0] = MAX(f[data[i]][0], 1);
		hmax = MAX(hmax, data[i]);
	}
	
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
f[j][0/1] = 

在前i盆花中, 最近保留的高度是j 0 是奇数盆 1偶数盆 能保留f
*/

