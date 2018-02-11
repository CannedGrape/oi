#include<cstdio>
#include<cstdlib>
#include<iostream>

//#define DEBUG

using namespace std;

struct station {
	int pass, stop;
} st[1005];

int n,m,s,sp = 0;
double stat[1005]={-1};

bool find(double num) {
	for(int i=1;i<=sp;++i) {
		if(stat[i]==num)return true;
	}
	return false;
}

int main() {
	#ifndef DEBUG
		freopen("level.in", "r", stdin);
		freopen("level.out", "w", stdout);
		ios::sync_with_stdio(false);
	#endif
	cin >> n >> m;
	for(int i=1;i<=m;++i) {
		cin >> s;
		bool f[1005] = {false};
		int a[1005] = {0};
		for(int j=1;j<=s;++j) {
			cin >> a[j];
			f[a[j]] = true;
		}
		int start=a[1], end=a[s];
		bool flag = true;
		
		for(int j=start;j<=end;++j) {
			if(!f[j]) flag = false;
		}
		if(flag) continue;
		for(int j=start;j<=end;++j) {
			st[j].pass++;
			if(f[j]) st[j].stop++;
		}
	}
	
	for(int i=1;i<=n;i++) {
		if(st[i].pass==0)continue;
		double xd = (double)st[i].stop / (double)st[i].pass;
		if(!(find(xd))) {
			stat[++sp] = xd;
		}
	}
	
	cout << sp << endl;
	#ifndef DEBUG
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
} 

