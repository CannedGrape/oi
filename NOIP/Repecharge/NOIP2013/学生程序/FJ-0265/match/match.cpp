#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
typedef long long ll;

const int maxn = 100005;
const int MOD = 99999997;

int a[maxn], b[maxn], temp[maxn], to[maxn], n, m, tn, t[maxn * 4];

void modify(int l, int r, int now, int lr)
{
	if (l == r)
	{
		t[now] += 1;
		return;
	}
	int mid = (l + r) / 2;
	if (lr <= mid) modify(l, mid, now * 2, lr);
	else modify(mid + 1, r, now * 2 + 1, lr);
	t[now] = t[now * 2] + t[now * 2 + 1];
}

int query(int l, int r, int now, int lf, int rt)
{
	if (l >= lf && r <= rt) return t[now];
	int mid = (l + r) / 2, ans = 0;
	if (lf <= mid) ans += query(l, mid, now * 2, lf, rt);
	if (rt >= mid + 1) ans += query(mid + 1, r, now * 2 + 1, lf, rt);
	return ans;
}

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), temp[i] = a[i];
	sort(temp, temp + n);
	m = unique(temp, temp + n) - temp;
	for (int i = 0; i < n; ++i)
		a[i] = lower_bound(temp, temp + m, a[i]) - temp;
		
	for (int i = 0; i < n; ++i)
	 	scanf("%d", &b[i]), temp[i] = b[i];
	sort(temp, temp + n);
	m = unique(temp, temp + n) - temp;
	for (int i = 0; i < n; ++i)
		b[i] = lower_bound(temp, temp + m, b[i]) - temp;
	
	for (int i = 0; i < n; ++i)
		to[a[i]] = i;
	for (int i = 0; i < n; ++i)
		b[i] = to[b[i]];
	
	int ans = 0;
	
	for (int i = n - 1; i >= 0; --i)
	{
		ans = (ans + query(0, n - 1, 1, 0, b[i])) % MOD;
		modify(0, n - 1, 1, b[i]);
	}
	printf("%d", ans);
	fclose(stdin);fclose(stdout);
}

