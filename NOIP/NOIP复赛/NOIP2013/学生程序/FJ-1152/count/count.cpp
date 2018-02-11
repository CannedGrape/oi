#include<cstdio>
#include<cstdlib>
#include<iostream>

//#define DEBUG

using namespace std;

int main() {
	#ifndef DEBUG
		freopen("count.in", "r", stdin);
		freopen("count.out", "w", stdout);
		ios::sync_with_stdio(false);
	#endif
	int n,x;
	unsigned long long ans = 0;
	cin >> n >> x;
	for(int i=1;i<=n;++i) {
		int t=i, k=0;
		while(t!=0) {
			k = t % 10; t /= 10;
			if(k==x) ans++;
		}
	}
	cout << ans << endl;
	#ifndef DEBUG
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
} 
