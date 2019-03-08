#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cctype>
#include <climits>

using namespace std;

const int maxn = 100000 + 50;
const long long Limit = 1LL << 60;
const int MOD = 99999997;
struct Ct
{
	int value, pos;
};

bool operator<(Ct a, Ct b)
{
	return a.value < b.value;
}

int a[maxn] = {0};
int b[maxn] = {0};
int ca[maxn] = {0};

Ct A[maxn];
Ct B[maxn];

int n;

long long ans = 0;

inline void IncAns(long long p)
{
	ans += p;
	if (ans >= Limit)
		ans %= MOD;
}

void MegeSort(int L, int R)
{
	if (L >= R)
	{
		return;
	}
	int Mid = (L + R) >> 1;
	MegeSort(L, Mid);
	MegeSort(Mid + 1, R);
	int i = L, j = Mid + 1;
	int p = L;
	while (i <= Mid && j <= R)
	{
		if (b[i] < b[j])
		{
			ca[p++] = b[i++];
		}
		else
		{
			IncAns(Mid - i + 1);
			ca[p++] = b[j++];
		}
	}
	for (int ii = i; ii <= Mid; ii++)
	{
		ca[p++] = b[ii];
	}
	for (int jj = j; jj <= R; jj++)
	{
		ca[p++] = b[jj];
	}
	for (int k = L; k <= R; k++)
	{
		b[k] = ca[k];
	}
}

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		A[i].value = a[i];
		A[i].pos = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", b + i);
		B[i].value = b[i];
		B[i].pos = i;
	}
	sort(A + 1, A + 1 + n);
	sort(B + 1, B + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		b[B[i].pos] = A[i].pos;
	}
	MegeSort(1, n);
	printf("%lld\n", ans);
}
