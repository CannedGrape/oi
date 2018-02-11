#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
struct P{
	int ex,ey,sx,sy;
};
P q[1000000];
bool map[31][31];
int head,tail,cost[31][31][31][31],n,m,ex,ey,sx,sy,tx,ty,Q;
int c[31][31],Col;
int stx[4]={1,-1,0,0};
int sty[4]={0,0,-1,1};
bool check(P now){
	if(now.ex<1||now.ey<1) return false ;
	if(now.ex>n||now.ey>m) return false ;
	if(!map[now.ex][now.ey]) return false ;
	return true ;
}
void put(P now){
	printf("%d %d %d %d\n",now.ex,now.ey,now.sx,now.sy);
}
int cal(int x,int y){
	int temp=0,tot=0;
	for(int i=0;i<4;i++)
	  if(x+stx[i]>0&&x+stx[i]<=n)
	  	if(y+sty[i]>0&&y+sty[i]<=m){
	  		++tot;
			if(!map[x+stx[i]][y+sty[i]]) ++temp;
		}
	if(temp+1==tot) return true ;
	return false ;
}
bool near(){
	
}
int bfs(){
	if(sx==tx&&sy==ty) return 0;
	head=tail=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int ii=0;ii<=n;ii++)
				for(int jj=0;jj<=m;jj++)
					cost[i][j][ii][jj]=0;
	q[1].ex=ex;
	q[1].ey=ey;
	q[1].sx=sx;
	q[1].sy=sy;
	cost[ex][ey][sx][sy]=1;
	while(head<=tail){
		P now=q[head++];
		int v=cost[now.ex][now.ey][now.sx][now.sy]+1;
		if(v>=4) continue;
		for(int i=0;i<4;i++){
			P temp;
			temp.ex=now.ex+stx[i];
			temp.ey=now.ey+sty[i];
			if(!check(temp)) continue ;
			if(temp.ex==now.sx&&temp.ey==now.sy){
				temp.sx=now.ex;
				temp.sy=now.ey;
			} else {
				temp.sx=now.sx;
				temp.sy=now.sy;
			}
			if(cost[temp.ex][temp.ey][temp.sx][temp.sy]) continue ;
			cost[temp.ex][temp.ey][temp.sx][temp.sy]=v;
			if(temp.sx==tx&&temp.sy==ty) return v-1;
			q[++tail]=temp;
		}
    }
    return -1;
}
int BFS(){
	int t=bfs();
	if(t!=-1) return t;
	if(c[sx][sy]!=c[tx][ty]) return -1;
	if(c[ex][ey]!=c[tx][ty]) return -1;
	if(cal(sx,sy)) return -1;
	if(cal(tx,ty)) return -1;
	head=tail=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int ii=0;ii<=n;ii++)
				for(int jj=0;jj<=m;jj++)
					cost[i][j][ii][jj]=0;
	q[1].ex=ex;
	q[1].ey=ey;
	q[1].sx=sx;
	q[1].sy=sy;
	cost[ex][ey][sx][sy]=1;
	while(head<=tail){
		P now=q[head++];
		int v=cost[now.ex][now.ey][now.sx][now.sy]+1;
		for(int i=0;i<4;i++){
			P temp;
			temp.ex=now.ex+stx[i];
			temp.ey=now.ey+sty[i];
			if(!check(temp)) continue ;
			if(temp.ex==now.sx&&temp.ey==now.sy){
				temp.sx=now.ex;
				temp.sy=now.ey;
			} else {
				temp.sx=now.sx;
				temp.sy=now.sy;
			}
			if(cost[temp.ex][temp.ey][temp.sx][temp.sy]) continue ;
			cost[temp.ex][temp.ey][temp.sx][temp.sy]=v;
			if(temp.sx==tx&&temp.sy==ty) return v-1;
			q[++tail]=temp;
		}
    }
    return -1;
}
void DFS(int x,int y){
	if(x<1||y<1) return ;
	if(x>n||y>m) return ;
	if(!map[x][y]) return ;
	if(c[x][y]) return ;
	c[x][y]=Col;
	for(int i=0;i<4;i++)
		DFS(x+stx[i],y+sty[i]);
}
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j]&&!c[i][j]){
				++Col;
				DFS(i,j);
			}
	while(Q--){
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		printf("%d\n",BFS());
	}
	return 0;
}

