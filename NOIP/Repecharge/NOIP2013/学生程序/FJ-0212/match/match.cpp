#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 100050
#define MOD 99999997
#define LOWBIT(x) ( (x) & (-x) )

struct Data
{
	int id;
	int h;
};

Data data1[MAXN], data1bak[MAXN], data2[MAXN];
int c[MAXN];
map<int, int> m, m2;
int n;

bool operator < (Data a, Data b)
{
	return a.h < b.h;
}

int getSum(int x)
{
	int ans = 0;
	for (int i=x; i>=1; i-=LOWBIT(i))
		ans += c[i];
	return ans;
}

void update(int x, int delta)
{
	for (int i=x; i<=n; i+=LOWBIT(i))
		c[i] += delta;
}

int main() {
	int ans = 0;
	
	freopen("match.in", "r", stdin);
	freopen("match.out ", "w", stdout);
	scanf("%d", &n);
	
	for (int i=1; i<=n; i++)
	{
		data1[i].id = i;
		scanf("%d", &data1[i].h);
		data1bak[i] = data1[i];
	}
	for (int i=1; i<=n; i++)
	{
		data2[i].id = i;
		scanf("%d", &data2[i].h);
	}
	
	sort(data1bak+1, data1bak+n+1);
	sort(data2+1, data2+n+1);
	
	for (int i=1; i<=n; i++)
	{
		m[i] = data2[i].id;
		m2[data1bak[i].h] = i;
	}
	
	for (int i=1; i<=n; i++)
	{
		ans += i - 1 - getSum(m[m2[data1[i].h]]);
		ans %= MOD;
		update(m[m2[data1[i].h]], 1);
	}
	printf("%d\n", ans);	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
