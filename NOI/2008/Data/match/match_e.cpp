 #include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

	int n, x;
	int prev[2000], next[2000], list[2000], anslist[2000], a[2000], limit[2000], ans[2000];
	double p[2000][2000], pos[2000][100], ansvalue, d;
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

	int main(int argc, char *argv[])
	{
		int i, j;
		FILE *inFile, *outFile, *ansFile;
		inFile = fopen(argv[1], "r");
		outFile = fopen(argv[2], "r");
		ansFile = fopen(argv[3], "r");
		fscanf(inFile, "%d", &n);
		x = 0;
		for (int t = 1; t < n; t *= 2)	x ++;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
			{
				double t;
				fscanf(inFile, "%lf", &t);
				p[i][j] = t;
			}
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (i != j && (p[i][j] + p[j][i] < 0.99 || p[i][j] + p[j][i] > 1.01))
				{
					printf("Input format error\n10\n");
					return 0;
				}
		if (ansFile == NULL)
		{
			printf("No standard output. :(\n0\n");
			return 0;
		}
		if (inFile == NULL)
		{
			printf("No input. :(\n0\n");
			return 0;
		}
		if (outFile == NULL)
		{
			printf("No output. :(\n0\n");
			return 0;
		}
		for (int i = 1; i <= x + 1; i ++)
			fscanf(inFile, "%d", &a[i]);
		for (int i = 1; i <= n; i ++)
			fscanf(ansFile, "%d", &ans[i]);
		fscanf(ansFile, "%lf", &ansvalue);
		fscanf(ansFile, "%lf", &d);
		for (int i = 1; i <= n; i ++)
			if (fscanf(outFile, "%d", &list[i]) != 1)
			{
				printf("Format error:Less than n numbers\n0\n");
				return 0;
			}
		int xy[2000];
		memset(xy, 0, sizeof(xy));
		for (int i = 1; i <= n; i ++)
			if (list[i] > n || list[i] < 1)
			{
				printf("Format error:Not a permutation\n0\n");
					return 0;
			}
			else
				if (xy[list[i]] > 0)
				{
					printf("Format error:Not a permutation\n0\n");
					return 0;
				}
			else
				xy[list[i]] = i;
		if (list[1] != 1)
		{
			printf("Format error:The first number isn't 1\n0\n");
			return 0;
		}
		memset(pos, 0, sizeof(pos));
		calc(1, n, x + 1);
		double cur = 0;
		for (int i = 1; i <= x + 1; i ++)
			cur += pos[1][i] * a[i];
		printf("OK. Your answer is %.8lf\n", cur);
		if (cur < ansvalue * d)
			printf("1\n");
		else
			if (cur > ansvalue + 1)
				printf("12\n");
		else {
			//printf( "%lf %lf\n", cur, ansvalue );
			if (cur >= ansvalue-0.000001)
				printf("10\n");
			else
				printf("%d\n", 2 + int((cur - ansvalue * d) / (ansvalue - ansvalue * d) * 8));
		}
		/*if (fscanf(outFile, "%d", &b2) == 1 && b2 == b)
			printf("Correct! :D\n10\n");
		else
			printf("Correct minimal possible inconvenience! :)\n4\n");*/
		return 0;
	}
