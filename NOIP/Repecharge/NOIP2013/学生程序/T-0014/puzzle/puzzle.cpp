# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <algorithm>
# include <math.h>
# include <time.h>
using namespace std;
int n,m,q,map[32][32],xw,yw,xg,yg,xe,ye,ans=2147483647;
int qq[400010][4];
int pp[400010];
int dx[]={0,0,0,1,-1},dy[]={0,1,-1,0,0};
bool hashlist[700010] = {};
void gtrue(int x,int y,int xx,int yy) {hashlist[x*6400+y*1600+xx*400+yy*100]=true;}
void tryy(int x,int y,int xx,int yy,int ex,int ey) {
	int head,tail;
	head=0;
	tail=1;
	qq[1][0]=x;
	qq[1][1]=y;
	qq[1][2]=xx;
	qq[1][3]=yy;
	pp[1]=0;
	while(head<tail) {
		head ++;
		int xa,xb,ya,yb;
		xa=qq[head][0];
		ya=qq[head][1];
		xb=qq[head][2];
		yb=qq[head][3];
		for (int i=0;i<=3;i++) {
			int xxx=xa+dx[i],yyy=xb+dy[i];
			if(xxx==xa&&yyy==ya)
			if(map[xxx][yyy]!=0 && hashlist[xxx*6400+yyy*1600+ya*400+yb*100]!=true && xxx>=1 && xxx<=n && yyy>=1 && yyy<=m) {				
				gtrue(xxx,yyy,xb,yb);
				tail++;
				pp[tail]=pp[head]+1;
				qq[tail][0]=xxx;
				qq[tail][1]=yyy;
				qq[tail][2]=xb;
				qq[tail][3]=yb;
				if(xxx==ex&&yyy==ey) {
					printf("%d\n",pp[tail]);
					exit(0);
				}
			}
		}
	}
}
int main() {
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);

	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &map[i][j]);


	for (int i = 1; i <= q; ++i) {
		scanf("%d %d %d %d %d %d",&xw,&yw,&xg,&yg,&xe,&ye);
		tryy(xg,yg,xw,yw,xe,ye);
	}
	printf("-1\n");
	return 0;
}
