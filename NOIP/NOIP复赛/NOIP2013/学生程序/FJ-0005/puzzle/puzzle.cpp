#include<cstdio>
#include<cstring>

const int Mv[][2]={{1,0},{-1,0},{0,1},{0,-1}};

struct my_node{
	int x,y,ex,ey,s;
	my_node(int x=0,int y=0,int ex=0,int ey=0,int s=-1):x(x),y(y),ex(ex),ey(ey),s(s){}
} q[810005];

int n,m,qs,qh,qt,mp[35][35],f[35][35][35][35];
int main(){
	freopen("puzzle.in","r",stdin),freopen("puzzle.out","w",stdout);
	scanf("%d %d %d",&n,&m,&qs);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) scanf("%d",&mp[i][j]),mp[i][j]^=1;
	for(int i=1;i<=n;++i) mp[i][0]=mp[i][m+1]=1;
	for(int i=1;i<=m;++i) mp[0][i]=mp[n+1][i]=1;
	for(int ex,ey,sx,sy,tx,ty,flag;qs--;){
		scanf("%d %d %d %d %d %d",&ex,&ey,&sx,&sy,&tx,&ty),memset(f,-1,sizeof(f)),flag=0;
		for(q[qh=qt=1]=my_node(sx,sy,ex,ey,f[sx][sy][ex][ey]=0);qh<=qt&&!flag;++qh){
				my_node now=q[qh],next;
				for(int i=0;i<4&&!flag;++i){
					next.ex=now.ex+Mv[i][0],next.ey=now.ey+Mv[i][1];
					if (mp[next.ex][next.ey]) continue;
					if ((next.ex==now.x)&&(next.ey==now.y)) next.x=now.ex,next.y=now.ey;
					else next.x=now.x,next.y=now.y;
					if (!~f[next.x][next.y][next.ex][next.ey]) next.s=f[next.x][next.y][next.ex][next.ey]=now.s+1,q[++qt]=next;
					if ((next.x==tx)&&(next.y==ty)) printf("%d\n",next.s),flag=1;
				}
			}
		if (!flag) puts("-1");
	}
	return 0;
}
