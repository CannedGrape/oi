#include<iostream>
#include<cstdio>
using namespace std;
int n,m,q,ans;
int ex[501],ey[501],sx[501],sy[501],tx[501],ty[501];
int qp[31][31]; bool f[501];
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++) scanf("%d",&qp[i][j]);
	for(i=1;i<=q;i++) 
	scanf("%d%d%d%d%d%d",&ex[i],&ey[i],&sx[i],&sy[i],&tx[i],&ty[i]);
	
	
	for(i=1;i<=q;i++)
	{ if (f[i]==0) printf("-1\n"); else printf("%d\n",ans); }
	return 0;
}
