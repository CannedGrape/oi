#include <iostream>
#include <cassert>

using namespace std;

int main() {
	int i;
	int d[10];
	for (i = 0; i < 10; i++) {
		cin >> d[i];
		assert(100 <= d[i] && d[i] <= 200);
	}
	int c;
	cin >> c;
	assert(100 <= c && c <= 120);
	{char c; assert(!(cin >> c));}
	int num = 0;
	for (i = 0; i < 10; i++) {
		if (c + 30 >= d[i]) num++;
	}
	cout << num << endl;
}
