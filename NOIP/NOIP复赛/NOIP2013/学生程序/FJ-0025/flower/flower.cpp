#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxn = 100050;

int dp[maxn][5];
int N, A[maxn];


inline int max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
    	scanf("%d", A + i);
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= N; ++i)
    {
		int x, y; //x,0->lower , y,1->upper
		for(x = i - 1; x > 0; --x)
			if(A[x] < A[i])
				break;
		for(y = i - 1; y > 0; --y)
			if(A[y] > A[i])
				break;
		if(x > 0 && y > 0)
		{
			dp[i][0] = dp[x][1] + 1;
			dp[i][1] = dp[y][0] + 1;
		}
		else if(x > 0)
		{
			dp[i][0] = dp[x][1] + 1;
			dp[i][1] = 1;
		}
		else
		{
			dp[i][1] = dp[y][0] + 1;
			dp[i][0] = 1;
		}
	}
	printf("%d\n", max(dp[N][0], dp[N][1]));

    return 0;
}

