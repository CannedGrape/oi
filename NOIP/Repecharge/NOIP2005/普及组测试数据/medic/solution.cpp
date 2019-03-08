#include <iostream>
#include <cassert>

using namespace std;

int tt[200];
int vv[200];

int dp[1005][105];

int main () {
	int T, M;
	cin >> T >> M;
	assert(1 <= T && T <= 1000);
	assert(1 <= M && M <= 100);
	int i, j;
	for (i = 1; i <= M; i++) {
		cin >> tt[i] >> vv[i];
		assert(1 <= tt[i] && tt[i] <= 100);
		assert(1 <= vv[i] && vv[i] <= 100);
	}
	for (i = 1; i <= T; i++) {
		for (j = 1; j <= M; j++) {
			int a = dp[i][j - 1];
			if (i >= tt[j]) {
				int b = dp[i - tt[j]][j - 1] + vv[j];
				if (b > a) a = b;
			}
			dp[i][j] = a;
		}
	}

	cout << dp[T][M] << endl;
	{char c;assert(!(cin >> c));}
	return 0;
}
