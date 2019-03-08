#include <cstdio>
using namespace std;
int sum,n,m,t,w,s[1002],ww[1002],p[1002][1002],f[1002][1002];
int check ()
{
	for (int i=1;i<=n;i++)
	    if (ww[i]!=0) return 0;
	return 1;
}
int main ()
{
	freopen ("level.in","r",stdin);
	freopen ("level.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf ("%d",&s[i]);t=2,w=1;
		for (int j=1;j<=s[i];j++) scanf ("%d",&p[i][j]);
		for (int j=p[i][1]+1;j<p[i][s[i]];j++)
			if (j==p[i][t]) t++;
			else f[i][w]=j,w++;
		ww[i]=w-1;
	}
	for (int i=1;i<m;i++)
	    for (int j=1;j<=s[i];j++)
	    {
			for (int k=1;k<=m;k++)
			if (f[s[i]][j]==s[k]) sum++,s[k]=0;
		}
	if (check ()) printf ("%d\n",sum+1);
	else printf ("%d\n",sum+2);
	return 0;
}
