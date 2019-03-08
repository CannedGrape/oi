#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
typedef long long ll;

const int maxn = 100005;

int h[maxn], tt[maxn], n, m, t1[maxn * 4], t2[maxn * 4], ans;

void modify1(int l, int r, int now, int lr, int v)
{
	if (l == r)
	{
		t1[now] = max(t1[now], v);
		return;
	}
	int mid = (l + r) / 2;
	if (lr <= mid) modify1(l, mid, now * 2, lr, v);
	else modify1(mid + 1, r, now * 2 + 1, lr, v);
	t1[now] = max(t1[now * 2], t1[now * 2 + 1]);
}

int query1(int l, int r, int now, int lf, int rt)
{
	if (lf > rt) return 0;
	if (l >= lf && r <= rt) return t1[now];
	int mid = (l + r) / 2, ans = 0;
	if (lf <= mid) ans = max(ans, query1(l, mid, now * 2, lf, rt));
	if (rt >= mid + 1) ans = max(ans, query1(mid + 1, r, now * 2 + 1, lf, rt));
	return ans;
}

void modify2(int l, int r, int now, int lr, int v)
{
	if (l == r)
	{
		t2[now] = max(t2[now], v);
		return;
	}
	int mid = (l + r) / 2;
	if (lr <= mid) modify2(l, mid, now * 2, lr, v);
	else modify2(mid + 1, r, now * 2 + 1, lr, v);
	t2[now] = max(t2[now * 2], t2[now * 2 + 1]);
}

int query2(int l, int r, int now, int lf, int rt)
{
	if (lf > rt) return 0;
	if (l >= lf && r <= rt) return t2[now];
	int mid = (l + r) / 2, ans = 0;
	if (lf <= mid) ans = max(ans, query2(l, mid, now * 2, lf, rt));
	if (rt >= mid + 1) ans = max(ans, query2(mid + 1, r, now * 2 + 1, lf, rt));
	return ans;
}

int main()
{
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &h[i]), tt[i] = h[i];
	sort(tt, tt + n);
	m = unique(tt, tt + n) - tt;
	for (int i = 0; i < n; ++i)
		h[i] = lower_bound(tt, tt + m, h[i]) - tt;
	for (int i = 0; i < n; ++i)
	{
		int ans1 = query1(0, m, 1, 0, h[i] - 1) + 1,
				ans2 = query2(0, m, 1, h[i] + 1, m) + 1;
		modify1(0, m, 1, h[i], ans2);
		modify2(0, m, 1, h[i], ans1);
		ans = max(ans, max(ans1, ans2));
	}
	printf("%d", ans);
	fclose(stdin);fclose(stdout);
}


