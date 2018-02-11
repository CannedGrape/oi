#include<cstdio>
int n,m,q,i,j,a[35][35],ex,ey,sx,sy,fx,fy,ans;
int abs(int x){
	return x>0?x:-x;
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	for(;q;--q){
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&fx,&fy);
		if(a[fx+1][fy]+a[fx-1][fy]+a[fx][fy-1]+a[fx][fy+1]==1){
			printf("-1\n");
			continue;
		}
		if(sx==fx||sy==fy)ans=abs(ex-sx)+abs(ey-sy)-1+abs(fx-sx)+abs(fy-sy);
		else ans=ans=abs(ex-sx)+abs(ey-sy)-1+3*(abs(fx-sx)+abs(fy)-sy);
		printf("%d\n",ans);
	}
	return 0;
}
