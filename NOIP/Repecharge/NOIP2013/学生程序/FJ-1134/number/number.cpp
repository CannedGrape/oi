#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int a[1000005],f[1000005],num[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int Max;
	int n,p;
	cin >> n >> p;
	cin >> num[1];
	a[1]=num[1];
	for (int i=2;i<=n;i++) {
		cin >> num[i];
		a[i]=max(max(a[i-1],a[i-1]+num[i]),num[i]);
	}
	f[1]=a[1];
	Max=f[1];
	for (int i=2;i<=n;i++) {
		f[i]=max(f[i-1]+a[i-1],f[1]+a[1]);
		Max=max(f[i],Max);
	}
	/*for (int i=1;i<=n;i++) cout << a[i] << " ";
	cout << endl;
	for (int i=1;i<=n;i++) cout << f[i] << " ";
	cout << endl;*/
	cout << (Max%p) << endl;
	return 0;
}
