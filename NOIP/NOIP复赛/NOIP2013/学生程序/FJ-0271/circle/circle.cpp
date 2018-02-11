#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 1000000 + 9;
bool app[N];
int num[N];
int Quick_power(long long a,int k,int MOD)
{
	long long res = 1;
	for (; k; a = a*a % MOD,k /= 2)
		if (k & 1) res = res*a % MOD;
	return res;
}
int main()
{
	freopen("circle.in","r",stdin); freopen("circle.out","w",stdout);
	int n,m,K,x,len;
	scanf("%d%d%d%d",&n,&m,&K,&x);
	app[x] = true; num[0] = x;
	for (int i = 1; true; ++i) {
		x = (x + m) % n;
		if (app[x]) {len = i;break;}
		app[x] = true;
		num[i] = x;
	}
	printf("%d\n",num[Quick_power(10,K,len)]);
	fclose(stdin); fclose(stdout);
}
