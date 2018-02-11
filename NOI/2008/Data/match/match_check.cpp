
	#include <algorithm>
	#include <cstdio>
	#include <iostream>
#include <memory.h>
	using namespace std;

	int n, x;
	int prev[2000], next[2000], list[2000], anslist[2000], a[2000], limit[2000];
	double p[2000][2000], pos[2000][100];
	double best;
	int sum, v;

	void calc(int l, int r, int steps)
	{
		if (steps == 1)	pos[list[l]][1] = 1;
		else
		{
			int mid = (l + r) / 2;
			calc(l, mid, steps - 1);
			calc(mid + 1, r, steps - 1);
			for (int i = l; i <= mid; i ++)
				for (int j = mid + 1; j <= r; j ++)
				{
					pos[list[i]][steps] += pos[list[i]][steps - 1] * pos[list[j]][steps - 1] * p[list[i]][list[j]];
					pos[list[j]][steps] += pos[list[i]][steps - 1] * pos[list[j]][steps - 1] * p[list[j]][list[i]];
				}
			for (int i = l; i <= r; i ++)
				pos[list[i]][steps - 1] -= pos[list[i]][steps];
		}
	}

	int main(int argv, char *argc[])
	{
	   char strin[25], strout[25];
	   sprintf(strin, "match%s.in\0", argc[1]);
	   sprintf(strout, "match%s.out\0", argc[1]);
		freopen(strin, "r", stdin);
		scanf("%d", &n);
		x = 0;
		for (int t = 1; t < n; t *= 2) x ++;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
			{
				double t;
				scanf("%lf", &t);
				p[i][j] = t;
			}
		for (int i = 1; i <= x + 1; i ++)
			scanf("%d", &a[i]);
		freopen(strout, "r", stdin);
		for (int i = 1; i <= n; i ++)
		   if (scanf("%d", &list[i]) != 1) {
		      printf("Format error\nLess than n numbers\n");
		      return 0;
		   }
		int xy[2000];
		memset(xy, 0, sizeof(xy));
		for (int i = 1; i <= n; i ++)
		   if (list[i] > n || list[i] < 1) {
		      printf("Format error\nNot a permutation\n");
		      return 0;
		   }
		   else
		      if (xy[list[i]] > 0) {
			 printf("Format error\nNot a permutation\n");
			 return 0;
		      }
		      else
			 xy[list[i]] = i;
		if (list[1] != 1) {
		   printf("Format error\nThe first number isn't 1\n");
		   return 0;
		}
		memset(pos, 0, sizeof(pos));
		calc(1, n, x + 1);
		double cur = 0;
		for (int i = 1; i <= x + 1; i ++)
			cur += pos[1][i] * a[i];
		printf("OK. Your answer is %.8lf.\n", cur);
		return 0;
	}
