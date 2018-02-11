#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#pragma warning(disable:4996);

using namespace std;

const int MAXN = 100001;

int n;
int s[MAXN][2];
int l[MAXN], h[MAXN];

int ans = 0;
bool bad = false;

int main()
{
	FILE *f = fopen("mobile.in", "rt");
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; ++i)
		fscanf(f, "%d %d", &s[i][0], &s[i][1]);
	fclose(f);
	for (int i = n; i >= 1; --i)
	{
		int l1, h1, l2, h2;
		if (s[i][0]==-1)
			l1 = h1 = 0;
		else
		{
			l1 = l[s[i][0]];
			h1 = h[s[i][0]];
		}
		if (s[i][1]==-1)
			l2 = h2 = 0;
		else
		{
			l2 = l[s[i][1]];
			h2 = h[s[i][1]];
		}
		l[i] = min(l1, l2) + 1;
		h[i] = max(h1, h2) + 1;
		if (h[i]-l[i]>1)
			bad = true;
		if (h1<h2 || l1<l2)
		{
			swap(l1, l2);
			swap(h1, h2);
			++ans;
		}
		if (h2>l1)
			bad = true;
	}
	FILE *fo = fopen("mobile.out", "wt");
	if (bad)
		ans = -1;
	fprintf(fo, "%d\n", ans);
	fclose(fo);
	return 0;
}
