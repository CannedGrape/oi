#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxn = 100050;

struct treenode
{
	int l, r, data, num;
};

struct rpack
{
	int data, now;
};

/*********************************************/

struct treenode tree[maxn * 4];
int A[maxn], N;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

inline int min(int a, int b)
{
	return a < b ? a : b;
}

void build(int left, int right, int now = 1)
{
	tree[now].l = left;
	tree[now].r = right;
	if(left == right)
	{
		tree[now].data = A[left];
		tree[now].num = left;
	}
	if(left < right)
	{
		int mid = (left + right) >> 1;
		build(left, mid, now * 2);
		build(mid + 1, right, now * 2 + 1);
		int t1 = tree[now * 2].data,
			t2 = tree[now * 2 + 1].data,
			n1 = tree[now * 2].num,
			n2 = tree[now * 2 + 1].num;
		if(t1 < t2)
		{
			tree[now].data = t1;
			tree[now].num = n1;
		}
		else
		{
			tree[now].data = t2;
			tree[now].num = n2;
		}
	}
}

struct rpack getmin(int left, int right, int now = 1)
{
	struct rpack rs, t1, t2;
	int tl = tree[now].l, tr = tree[now].r;
	int tm = (tl + tr) >> 1;
	if(left == tl && right == tr)
	{
		rs.data = tree[now].data;
		rs.now = tree[now].num;
		return rs;
	}
	if(right <= tm)
		return getmin(left, right, now * 2);
	if(left > tm)
		return getmin(left, right, now * 2 + 1);
	else
	{
		t1 = getmin(left, tm, now * 2);
		t2 = getmin(tm + 1, right, now * 2 + 1);
		if(t1.data < t2.data)
			return t1;
		else
			return t2;
	}
}

int solve(int left, int right, int cut = 0)
{
	if(left > right)
		return 0;
	if(left == right)
		return A[left] - cut;
	struct rpack rs = getmin(left, right);
	int mid = rs.now;
	return solve(left, mid - 1, cut + rs.data) +
		   solve(mid + 1, right, cut + rs.data) +
		   rs.data;
}

int main()
{
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
		scanf("%d", A + i);
	build(1, N);
	printf("%d\n", solve(1, N));

    return 0;
}

