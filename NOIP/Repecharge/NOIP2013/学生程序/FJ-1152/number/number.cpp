#include<cstdio>
#include<cstdlib>
#include<iostream>

//#define DEBUG

struct placement {
	int start, end;
} f[1000005];

long long n,p,a[1000005],v[1000005],s[1000005],mx;

using namespace std;

int count(int start, int end) {
	int t=0;
	for(int i=start;i<=end;++i) {
		t += a[i];
	}
	return t;
}

int main() {
	#ifndef DEBUG
		freopen("number.in", "r", stdin);
		freopen("number.out", "w", stdout);
		ios::sync_with_stdio(false);
	#endif
	cin >> n >> p;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	f[1].start = 1; f[1].end = 1; v[1] = a[1];
	for(int i=2;i<=n;++i) {
		if(v[i-1] >= v[i-1]+count(f[i-1].end+1, i)) {
			f[i] = f[i-1];
		} else {
			f[i].start = f[i-1].start;
			f[i].end = i;
		}
		v[i]=v[i-1]+a[i];
	}
	s[1] = a[1];
	long long ans = s[1];
	mx = -2147483647;
	for(int i=2;i<=n;++i) {
		if(s[i-1]+v[i-1]>=mx) mx=s[i-1]+v[i-1];
		s[i] = mx;
		if(mx>ans) ans = mx;
	}
	
	if(ans<0) {
		ans = -ans;
		cout << "-";
	}
	ans %= p;
	
	cout << ans << endl;
	#ifndef DEBUG
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
} 
