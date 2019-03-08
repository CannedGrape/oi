# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <math.h>
# include <algorithm>
using namespace std;

int n,m,s[1010],num[1010][1010];
int f[1010];
int max(int a,int b) {
	return a > b ? a : b;
}

int main() {
	//score 10-50
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d",&s[i]);
		for (int j = 1; j <= s[i]; ++j)
			scanf("%d",&num[i][j]);
	}
	
	for (int i = 1; i <= n; ++i) f[i] = 1;
	for (int i = 1; i <= m; ++i) {
		int st;
		bool mc = false;
		bool ok = true;
		if (i == 1) ok = false;
		else {
			for (int j = 1; j <= s[i]; ++j) {
				if (mc == false) {st = f[num[i][j]];mc = true;}
				else if (st != f[num[i][j]] && mc == true) {
					ok = false;
					break;
				}
			}
		}
		
		if (! ok) {
			int maxx = -2147483647;
			for (int j = 1; j <= s[i]; ++j)
				maxx = max (f[num[i][j]] + 1, maxx);
			for (int j = 1; j <= s[i]; ++j) 
				f[num[i][j]] = maxx;
		}
	}
	int ans = -2147483647;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, f[i]);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
