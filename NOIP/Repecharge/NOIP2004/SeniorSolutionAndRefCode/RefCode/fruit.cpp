#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

ifstream fin("fruit.in");
ofstream fout("fruit.out");

int n;
list <int> a, b;

void init() {
	int p;

	fin >> n;
	for (int i = 0; i < n; i ++) {
		fin >> p;
		a.push_back(p);
	}
	a.sort();
}

int get() {
	int ans;

	if (a.empty()) {
		ans = b.front(); b.pop_front(); return ans;
	}
	if (b.empty()) {
		ans = a.front(); a.pop_front(); return ans;
	}
	if (a.front() < b.front()) {
		ans = a.front(); a.pop_front(); return ans;
	} 
	else {
		ans = b.front(); b.pop_front();	return ans;
	}
}
		
void work() {
	int p, sum = 0;
	for (int i = 0; i < n - 1; i ++) {
		p = get() + get();
		b.push_back(p);
		sum += p;
	}
	fout << sum << endl;
}

int main() {
	init();
	work();
	return 0;
}
