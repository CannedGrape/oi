#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,k,sum=0;
	cin >> n >> k;
	for (int i=1;i<=n;i++) {
		int t=i;
		while (t) {
			if ((t%10)==k) sum++;
			t/=10;
		}
	}
	cout << sum << endl;
	return 0;
}
