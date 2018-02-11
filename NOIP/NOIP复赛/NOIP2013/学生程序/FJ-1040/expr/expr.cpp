# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <math.h>
# include <algorithm>
using namespace std;

char expc[1000100];
int len;
long long number[100010];
int n = 0;
char sign[100010];
int sn = 0;

bool isthedigit(char st) {
	if (st >= '0' && st <= '9') return true;
	return false;
}

int main() {
	//score 50-80
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",expc);
	len = strlen(expc);
	long long tmp = 0;
	// calc the string
	for (int i = 0; i < len; ++i) {
		if (isthedigit(expc[i])) {
			tmp = tmp * 10;
			tmp = tmp + expc[i] - '0';
		}
		else {
			number [++ n] = tmp;
			tmp = 0;
			sign [++ sn] = expc[i];
		}
	}
	number [++ n] = tmp;
	// calc the answer
	for (int i = 1; i <= sn; ++i) 
		if (sign[i] == '*') {
			number[i+1] = number[i] * number[i+1];
			number[i] = 0;
			sign[i] = '+';
		}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = ans + number[i];
		ans %= 10000;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
