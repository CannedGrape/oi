#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int N=41,M=9100,F[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
const int Inf=100000000,F2[4][3]={{2,0,3},{2,1,3},{1,2,0},{1,3,0}};

int n,m,map[N][N],f[N][N][4][3],dis[N][N][4];
int flag[N][N],flag2[N][N][4],qx[M],qy[M],qd[M],s,e;

struct Data{
	int x,y,f,a;
	Data(int _x=0,int _y=0,int _f=0,int _a=0){x=_x,y=_y,f=_f,a=_a;}
	bool operator <(const Data &d)const{
		return a>d.a;
	}
};

priority_queue<Data> q;

int Bfs(int sx,int sy,int tx,int ty){
	int i,x,y,d,_x,_y;
	memset(flag,0,sizeof(flag));
	flag[sx][sy]=1;s=0,e=0;
	qx[e]=sx,qy[e]=sy;qd[e++]=0;
	while (s!=e){
		x=qx[s],y=qy[s],d=qd[s++];
		if (x==tx && y==ty) return d;
		for(i=0;i<4;i++){
			if (map[_x=x+F[i][0]][_y=y+F[i][1]])
				if (!flag[_x][_y]){flag[_x][_y]=1;
					qx[e]=_x,qy[e]=_y,qd[e++]=d+1;
				}
		}
	}
	return -1;
}

int Dij(int tx,int ty){
	int i,x,y,fl,di;Data d;
	while (!q.empty()){
		d=q.top(),q.pop();
		if (flag2[d.x][d.y][d.f]) continue;flag2[d.x][d.y][d.f]=1;
		if (d.x==tx && d.y==ty) return d.a;
		for (i=0;i<3;i++){
			fl=F2[d.f][i];
			x=d.x+F[fl][0];
			y=d.y+F[fl][1];
			if (!map[x][y]) continue;
			if ((di=f[d.x-F[d.f][0]][d.y-F[d.f][1]][d.f][i])!=-1){
				if (di+d.a+1<dis[x][y][fl]){
					dis[x][y][fl]=di+d.a+1;
					q.push(Data(x,y,fl,dis[x][y][fl]));
				}
			}
		}
	}	
	return -1;
}

int main(){
	int i,j,k,ti,l,x,y,fl,ex,ey,sx,sy,tx,ty,d;
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&ti);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			if (!map[i][j]) continue;
			for (k=0;k<4;k++){
				if (map[x=i+F[k][0]][y=j+F[k][1]]){
					map[x][y]=0;
					for (l=0;l<3;l++){fl=F2[k][l];
						if (map[x+F[fl][0]][y+F[fl][1]])
							f[i][j][k][l]=Bfs(i,j,x+F[fl][0],y+F[fl][1]);
//						printf("%d %d %d %d %d %d %d\n",i,j,x,y,x+F[fl][0],y+F[fl][1],f[i][j][k][l]);
					}
					map[x][y]=1;
				}
			}
		}
	}
	while (ti--){
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		if (!map[sx][sy] || !map[ex][ey] || !map[tx][ty]){
			printf("-1\n");continue;
		}
		if (sx==tx && sy==ty){printf("0\n");continue;}
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				for (k=0;k<4;k++) dis[i][j][k]=Inf,flag2[i][j][k]=0;
		for (i=0;i<4;i++) dis[sx][sy][i]=0,flag2[sx][sy][k]=1;
		map[sx][sy]=0;
		for (i=0;i<4;i++){
			if (map[x=sx+F[i][0]][y=sy+F[i][1]]){
				if ((d=Bfs(ex,ey,x,y))!=-1){
					dis[x][y][i]=d+1;
					q.push(Data(x,y,i,d+1));
				}
			}
		}map[sx][sy]=1;
		printf("%d\n",Dij(tx,ty));
	}
	return 0;
}
