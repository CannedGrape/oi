# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <algorithm>
# include <math.h>

using namespace std;

long long n, m, k, x, ans;

int *f;

void openFile() {
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
}

void init() {
	f = new int [1000010];
	// windows
	//scanf("%I64d %I64d %I64d %I64d", &n, &m, &k, &x);
	// linux
	scanf("%lld %lld %lld %lld", &n, &m, &k, &x);
	for (int i=0;i<n;i++) f[i]=0;
}
int sc=1;
bool getlen(int len,int k) {
	int t=2;
	int tk=k,fk=k;
	int two=0,five=0;
	while (len != 1) {
		if (len%t==0) {
			len = len / t;
			if (t!=2 && t!=5) return false;
			if (t==2) two++,sc*=2;
			if (t==5) five++,sc*=5;
			t=2;
		}
		t++;
	}
	if (two>tk) sc /= ((two-tk)*2);
	if (five>fk) sc/= ((five-fk)*5);
	if (two<=tk && five<=fk) return true;
	else return false;
}

	
void work() {
	// calc the circle length
	int g = x, len = 1;
	f[x] = len;
	while(1) {
		g += m;
		g %= n;
		if (f[g] != 0) break;
		else {
			len++;
			f[g] = len;
		}
	}
	// circle length in 'len'
	// f[i] is the circle
	bool flag=getlen(len,k);
	if (flag==true) {
		printf("%d\n",x);
	}
	else {
		int p=len/sc;
		for (int i=1;i<=n;i++) if(f[i]==p) printf("%d\n",i);
	}
}

	
	
int main() {
	openFile();
	init();
	work();
	return 0;
}
