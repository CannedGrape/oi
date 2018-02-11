#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int P = 99999997, maxn = 100050;

int A[maxn], B[maxn], TA[maxn], TB[maxn], N;

int MarkA[maxn] = {0};

bool CMPA(int a, int b)
{
	return A[a] < A[b];
}

bool CMPB(int a, int b)
{
	return B[a] < B[b];
}

void init()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", A + i);
		TA[i] = i;
	}
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", B + i);
		TB[i] = i;
	}
}


int main()
{
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    int ans = 0, tt = 0;
    init();
    sort(TA + 1, TA + N + 1, CMPA);
    sort(TB + 1, TB + N + 1, CMPB);
    for(int i = 1; i <= N; ++i)
    {
		A[TA[i]] = i;
		B[TB[i]] = i;
	}
	for(int i = 1; i <= N; ++i)
	{
		if(A[i] != B[i])
		{
			MarkA[A[i]] = B[i];
		}
	}
	
	int begin, now, atime, t;
	for(int i = 1; i <= N; ++i)
	{
		if(MarkA[A[i]] != 0)
		{
			begin = A[i];
			now = MarkA[begin];
			MarkA[begin] = 0;
			atime = 0;
			while(now != begin && tt < N)
			{
				t = now;
				now = MarkA[now];
				MarkA[t] = 0;
				tt++;
				atime++;
				atime %= P;
			}
			ans += atime;
			ans %= P;
		}
		if(tt >= N)
			break;
	}
	printf("%d\n", ans % P);

    return 0;
}
