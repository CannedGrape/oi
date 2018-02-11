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

int a[100000],b[100000],n;
long long ansx,ansy;

void swapa(int c)
{
	int t;
	t=a[c]; a[c]=a[c+1]; a[c+1]=t;
}

void swapb(int c)
{
	int t;
	t=b[c]; b[c]=b[c+1]; b[c+1]=t;
}

void dg(int x,long long y,long long z)
{
	if (x==n) { 
	        	if (y+(a[x]-b[x])*(a[x]-b[x])<ansx) {ansx=y+(a[x]-b[x])*(a[x]-b[x]); ansy=z;} 
				else
	            if ((y+(a[x]-b[x])*(a[x]-b[x])==ansx)&&(z<ansy)) ansy=z; 
				return;
		      }
	if (y+(a[x]-b[x])*(a[x]-b[x])>ansx) return;
	if ((y+(a[x]-b[x])*(a[x]-b[x])==ansx)&&(z>=ansy)) return;
	dg(x+1,y+(a[x]-b[x])*(a[x]-b[x]),z);
	swapa(x);
	dg(x+1,y+(a[x]-b[x])*(a[x]-b[x]),z+1);
	swapb(x);
	dg(x+1,y+(a[x]-b[x])*(a[x]-b[x]),z+2);
	swapa(x);
	dg(x+1,y+(a[x]-b[x])*(a[x]-b[x]),z+1);
	swapb(x);
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	ansx=10000000; ansy=10000000;
	dg(1,0,0);
	cout << ansy%99999997 << endl;
	return 0;
}
