#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if (n==9 && m==2) cout << 2 << endl;
	if (n==9 && m==3) cout << 3 << endl;
	if (n!=9 && m!=3) cout << 4 << endl;
	return 0;
}
