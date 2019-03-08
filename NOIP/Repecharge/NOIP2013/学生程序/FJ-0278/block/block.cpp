#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
const int maxn = 100005;
typedef long long ll;
int n,h[maxn];
ll solve(int l,int r,int nowh) {
	if (l > r) return 0;
	int minh = 10005,k = l;
	for (int i = l; i <= r; ++i)
		if (h[i] < minh) {
			minh = h[i]; k = i;
		}
	//printf("%d %d %d %d\n",l,r,minh,nowh);
	ll s = solve(l,k - 1,minh) + solve(k + 1,r,minh);
	return s + h[k] - nowh;
} 
int main() {
	freopen("block.in","r",stdin); freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) scanf("%d",h + i);
	std::cout << solve(1,n,0);
	fclose(stdin); fclose(stdout);
}
	
