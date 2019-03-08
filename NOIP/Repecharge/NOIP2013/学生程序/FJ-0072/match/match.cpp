#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define P 99999997
#define MAX_N 400040

using namespace std;

int aa[MAX_N], bb[MAX_N], a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N], A[MAX_N], B[MAX_N], s[MAX_N];
int n;

void qsort(int l, int r, int A[], int a[])
{
    int i = l, j = r, m = A[a[(l + r) / 2]];
    while (i <= j)
    {
        while (A[a[i]] < m) i++;
        while (A[a[j]] > m) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if (l < j) qsort(l, j, A, a);
    if (i < r) qsort(i, r, A, a);
}

int lowbit(int x)
{
    return x & (-x);
}

void ins(int x)
{
    for(; x <= n; x += lowbit(x)) s[x]++;
}

int req(int x)
{
    int ret = 0;
    for(; x > 0; x -= lowbit(x)) ret += s[x];
    return ret;
}

long long calc(int a[])
{
    long long ret = 0;
    for (int i = n; i >= 1; i--)
    {
        ret += req(a[i]);
        ins(a[i]);
    }
    return ret;
}

int main()
{
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++) aa[i] = bb[i] = i;
    qsort(1, n, A, aa);
    qsort(1, n, B, bb);
    for (int i = 1; i <= n; i++) a[aa[i]] = i;
    for (int i = 1; i <= n; i++) b[bb[i]] = i;
    for (int i = 1; i <= n; i++) c[b[i]] = i;
    for (int i = 1; i <= n; i++) d[i] = c[a[i]];
    cout << calc(d) % P << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
