#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

long long n,m,k,x,y,ans;

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> x;
	y=0;
	for (int i=1; i<=10; i++) y=(y+m)%n;
	//cout << y << endl;
	for (int i=1; i<k; i++) y=y*10%n;
	//cout << y << endl;
	x=(x+y)%n;
	cout << x << endl;
	return 0;
}
