#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("chorus.in");
ofstream fout("chorus.out");

const int maxn = 100;

int n, a[maxn];
int incsq[maxn], decsq[maxn];

void init() {
	fin >> n;
	for (int i = 0; i < n; i ++)
		fin >> a[i];
}

void LIncSeq()
{
	int i, low, high, mid, ans = 0;
	int sol[maxn];

	for (i = 0; i < n; i ++) {
		low = 1; high = ans;
		while (low <= high) {
			mid = (low + high) >> 1;
			if (sol[mid] < a[i]) low = mid + 1;
			else high = mid - 1;
		}
		if (low > ans) ans ++;
		sol[low] = a[i];
		incsq[i] = ans;
	}
}

void LDecSeq()
{
	int i, low, high, mid, ans = 0;
	int sol[maxn];

	for (i = 0; i < n; i ++) {
		low = 1; high = ans;
		while (low <= high) {
			mid = (low + high) >> 1;
			if (sol[mid] > a[i]) low = mid + 1;
			else high = mid - 1;
		}
		if (low > ans) ans ++;
		sol[low] = a[i];
		decsq[i] = ans;
	}
}

void work() {
	int i, max = 0;

	LIncSeq();
	LDecSeq();

	for (i = 0; i < n; i ++)
		if (incsq[i] + decsq[i] - 1 > max)
			max = incsq[i] + decsq[i] - 1;

	fout << n - max << endl;
}

int main() {
	init();
	work();
	return 0;
}
