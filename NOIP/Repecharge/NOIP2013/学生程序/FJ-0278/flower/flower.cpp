#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn = 100005;
int n,a[maxn],f[maxn];
bool min[1005][1005],max[1005][1005];
void prepare1() {
	for (int i = 1; i <= n + 1; ++i) {
		int minh = a[i];
		for (int j = i + 1; j <= n + 1; ++j) {
			if (a[j] > minh && a[i] > minh) min[i][j] = true;
			minh = std::min(minh,a[j]);
		}
	}	
}
void prepare2() {
	for (int i = 1; i <= n + 1; ++i) {
		int maxh = a[i];
		for (int j = i + 1; j <= n + 1; ++j) {
			if (a[j] < maxh && a[i] < maxh) max[i][j] = true;
			maxh = std::max(maxh,a[j]);
		}
	}	
}
int work1() {
	memset(f,0,sizeof(f));
	f[1] = 1;
	for (int i = 2; i <= n + 1; ++i) {
		int tmp = f[i - 1];
		for (int j = i - 1; j >= 1; --j)
			if (min[j][i]) tmp = std::max(tmp,f[j] + 2);
		f[i] = tmp;
	}
	return std::max(f[n],f[n + 1] - 1);
}
int work2() {
	memset(f,0,sizeof(f));
	f[1] = 1;
	for (int i = 2; i <= n + 1; ++i) {
		int tmp = f[i - 1];
		for (int j = i - 1; j >= 1; --j)
			if (max[j][i]) tmp = std::max(tmp,f[j] + 2);
		f[i] = tmp;
	}
	return std::max(f[n],f[n + 1] - 1);
}
void work() {
	memset(min,false,sizeof(min));
	memset(max,false,sizeof(max));
	int ans;
	a[n + 1] = 1000001;
	prepare1();
	ans = work1();
	
	a[n + 1] = -1;
	prepare2();
	ans = std::max(ans,work2());
	
	printf("%d",ans);
}
int WORK1() {
	memset(f,0,sizeof(f));
	f[1] = 1;
	for (int i = 2; i <= n + 1; ++i) {
		int tmp = 0,minh = a[i];
		for (int j = i - 1; j >= 1; --j) {
			if (a[j] > minh && a[i] > minh) {
				tmp = f[j] + 2; break;
			}
			minh = std::min(a[j],minh);
		}
		f[i] = std::max(tmp,f[i - 1]);
	}
	return std::max(f[n],f[n + 1] - 1);
}
int WORK2() {
	memset(f,0,sizeof(f));
	f[1] = 1;
	for (int i = 2; i <= n + 1; ++i) {
		int tmp = 0,maxh = a[i];
		for (int j = i - 1; j >= 1; --j) {
			if (a[i] < maxh && a[j] < maxh) {
				tmp = f[j] + 2; break;
			}
			maxh = std::max(a[j],maxh);
		}
		f[i] = std::max(tmp,f[i - 1]);
	}
	return std::max(f[n],f[n + 1]  - 1);
}
void WORK(){
	a[n + 1] = 1000001;
	int ans = WORK1();
	
	a[n + 1] = -1;
	ans = std::max(ans,WORK2());
	printf("%d",ans);
}
int main() {
	freopen("flower.in","r",stdin); freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) scanf("%d",a + i);
	if (n <= 1000) work();
	else WORK();
	fclose(stdin); fclose(stdout);
}
