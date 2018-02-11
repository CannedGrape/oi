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

int pd[10000],map[10000][200],a[100000],b[100000],c[100000],f[1000][1000],ans,x,y,n,m,d[10000],q;

void dfs(int k,int minx)
{
	if (k==y) {if (minx>ans) ans=minx; return;}
	if (minx<=ans) return; 
	pd[k]=1;
	for (int j=1; j<=d[k]; j++)
	{
		int t=map[k][j];
		if (pd[b[t]]==0) dfs(b[t],min(minx,c[t]));
	}
	pd[k]=0;
}	

void work2()
{
	int a1,b1,c1;
    memset(f,-1,sizeof(f));
	for (int i=1; i<=m; i++)
	{
		cin >> a1 >> b1 >> c1;
		f[a1][b1]=c1;
		f[b1][a1]=c1;
	}
	for (int k=1; k<=n; k++)
	  for (int i=1; i<=n; i++)
	    for (int j=1; j<=n; j++)
	      if (f[i][j]<min(f[i][k],f[k][j])) f[i][j]=min(f[i][k],f[k][j]);
	cin >> q;
	for (int i=1; i<=q; i++) 
	{
		cin >> a1 >> b1;
		cout << f[a1][b1] << endl;
	}
}

void work1()
{
	for (int i=1; i<=m; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		a[i+m]=b[i]; b[i+m]=a[i]; c[i+m]=c[i];
		d[a[i]]++; d[b[i]]++;
		map[a[i]][d[a[i]]]=i;
		map[b[i]][d[b[i]]]=i+m;
	}
	cin >> q;
	for (int i=1; i<=q; i++)
	{
		cin >> x >> y;
		ans=-1;
		dfs(x,1000000);
		cout << ans << endl;
	}
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	if (n*n*n>200000000) work1(); else work2();
	return 0;
}
