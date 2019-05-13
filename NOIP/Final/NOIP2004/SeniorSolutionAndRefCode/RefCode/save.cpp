#include <fstream>
using namespace std;

ifstream fin("save.in");
ofstream fout("save.out");

void init() {
	int p, save = 0, cnt = 0;

	for (int i = 1; i <= 12; i ++) {
		fin >> p;
		cnt = cnt + 300 - p;
		while (cnt >= 100) {
			save += 100;
			cnt  -= 100;
		}
		if (cnt < 0) {
			fout << - i << endl;
			return;
		}
	}
	fout << cnt + int(save * 1.2) << endl;
}

int main() {
	init();
	return 0;
}
