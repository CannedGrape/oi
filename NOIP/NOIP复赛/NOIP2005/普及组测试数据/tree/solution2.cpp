#include <iostream>
#include <cassert>

using namespace std;

int used[10005];

int main() {
	int L, M;
	cin >> L >> M;
	assert(1 <= L && L <= 10000);
	assert(1 <= M && M <= 100);
	int i;
	for (i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		assert(0 <= a && a < b && b <= L);
		int j;
		for (j = a; j <= b; j++) used[j] = 1;
	}
	{char c; assert(!(cin >> c));}
	int num = 0;
	for (i = 0; i <= L; i++) {
		if (used[i] == 0) num ++;
	}
	cout << num << endl;
	return 0;
}
