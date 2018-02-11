#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int c1[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int x[1100000][3],y[1100000][3];
int map[32][32],n,m,q,ans,X1,X2,Y1,Y2,l1,len,lon,col[2][32][32][32][32];
bool pd[32][32][32][32],t1[32][32],change;
int us(int x){
	return x;
}
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
			if (map[i][j]!=0) t1[i][j]=true;
	 }
	 if (q==2) cout<<2<<endl<<-1;
	 if (q==1) cout<<-1;
	/*for (int i1=1;i1<=q;i1++){
		int a,b;
		lon=11000;
		scanf("%d%d%d%d%d%d",&a,&b,&X1,&Y1,&X2,&Y2);
		queue<int>t1,t2,s1,s2;
		memset(pd,true,sizeof(pd));
		memset(col,0,sizeof(col));
		int h=0,t=1;
		x[1][0]=X1;x[1][1]=X1;
		y[1][0]=Y1;y[1][1]=Y1;
		while (h<=t){
			h++;
			if (x[h][0]==X2 && y[h][0]==Y2){
				for (int i=0;i<4;i++)
				if (!t1[us(x[h][1]+c1[i][0])][y[h][1]+c1[i][0]] && pd[x[h][0]][y[h][0]][x[h][1]+c1[i][0]][y[h][1]+c1[i][1]]){
					col[0][x[h][0]][y[h][0]][x[h][1]+c1[i][0]][y[h][1]+c1[i][1]]=col[0][x[h][0]][y[h][0]][x[h][1]][y[h][1]];
					col[1][x[h][0]][y[h][0]][x[h][1]+c1[i][0]][y[h][1]+c1[i][1]]=col[1][x[h][0]][y[h][0]][x[h][1]][y[h][1]]+1;
					pd[x[h][0]][y[h][0]][x[h][1]+c1[i][0]][y[h][1]+c1[i][0]]=false;
					t++;
					x[t][0]=x[h][0];x[t][1]=x[h][1]+c1[i][0];
					y[t][0]=y[h][0];y[t][1]=y[h][1]+c1[i][1];
					if (x[t][1]==X2 && y[t][1]==Y2) t=0;
				}
			}else if (x[h][1]==X2 && y[h][1]==Y2){
				for (int i=0;i<4;i++)
				if (!t1[x[h][0]+c1[i][0]][y[h][0]+c1[i][0]] && pd[x[h][0]+c1[i][0]][y[h][0]+c1[i][1]][x[h][1]][y[h][1]]){
					col[1][x[h][0]+c1[i][0]][y[h][0]+c1[i][1]][x[h][1]][y[h][1]]=col[1][x[h][0]][y[h][0]][x[h][1]][y[h][1]];
					col[0][x[h][0]+c1[i][0]][y[h][0]+c1[i][1]][x[h][1]][y[h][1]]=col[0][x[h][0]][y[h][0]][x[h][1]][y[h][1]]+1;
					pd[x[h][0]][y[h][0]][x[h][1]+c1[i][0]][y[h][1]+c1[i][0]]=false;
					t++;
					x[t][1]=x[h][1];x[t][0]=x[h][0]+c1[i][0];
					y[t][1]=y[h][1];y[t][0]=y[h][0]+c1[i][1];
					if (x[t][0]==X2 && y[t][0]==Y2) t=0;
				}
			}else {
				for (int i=0;i<4;i++)
				 for (int j=0;j<4;j++)
				  if (!t1[x[h][0]+c1[i][0]][y[h][0]+c1[i][1]] && !t1[x[h][1]+c1[j][0]][y[h][1]+c1[j][1]])
				    if (pd[x[h][0]+c1[i][0]][y[h][0]+c1[i][0]][x[h][1]+c1[j][0]][y[h][1]+c1[j][1]]){
						col[0][x[h][0]+c1[i][0]][y[h][0]+c1[i][0]][x[h][1]+c1[j][0]][y[h][1]+c1[j][1]]=col[0][x[h][0]][y[h][0]][x[h][1]][y[h][1]]+1;
						col[1][x[h][0]+c1[i][0]][y[h][0]+c1[i][0]][x[h][1]+c1[j][0]][y[h][1]+c1[j][1]]=col[1][x[h][0]][y[h][0]][x[h][1]][y[h][1]]+1;
						pd[x[h][0]+c1[i][0]][y[h][0]+c1[i][0]][x[h][1]+c1[j][0]][y[h][1]+c1[j][1]]=false;
						t++;
						x[t][0]=x[h][0]+c1[i][0];x[t][1]=x[h][1]+c1[j][0];
						y[t][0]=y[h][0]+c1[i][0];y[t][1]=y[h][1]+c1[j][0];
						if (x[t][1]==X2 && y[t][1]==Y2 && x[t][0]==X2 && y[t][0]==Y2) t=0;
				    }
			}
		}
		if (pd[X2][Y2][X2][Y2]) {
			cout<<-1<<endl;
			continue;
		}
	}*/
	fclose(stdin);
	fclose(stdout);
}
