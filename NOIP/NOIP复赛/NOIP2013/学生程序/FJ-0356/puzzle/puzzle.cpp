#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=32;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int i,j,n,m,q,EX,EY,SX,SY,TX,TY,bo;
int dis[maxn][maxn][maxn][maxn],vis[maxn][maxn][maxn][maxn];
int in[maxn][maxn],head,tail;
int Q[maxn*maxn*maxn*maxn][4];
inline int abs(int a){
	if(a<0)return -a; else return a;
}
int BFS(){
	int movex,movey,freex,freey,i;
	int newmovex,newmovey,newfreex,newfreey;
	head=0; tail=1;
	dis[SX][SY][EX][EY]=0;
	memset(vis,0,sizeof(vis));
	vis[SX][SY][EX][EY]=1;
	Q[1][0]=SX; Q[1][1]=SY; Q[1][2]=EX; Q[1][3]=EY;
	while(head!=tail){
		++head;
		movex=Q[head][0]; movey=Q[head][1]; freex=Q[head][2]; freey=Q[head][3];
		for(i=0;i<4;i++){
			newfreex=freex+dx[i]; newfreey=freey+dy[i];
			if(!in[newfreex][newfreey])continue;
			if(newfreex==movex&&newfreey==movey){
				newmovex=freex; newmovey=freey;
			}else{
				newmovex=movex; newmovey=movey;
			}
			if(vis[newmovex][newmovey][newfreex][newfreey])continue;
			if(bo)
			if(!(newmovex==SX&&newmovey==SY)&&abs(newmovex-newfreex)+abs(newmovey-newfreey)>3)continue;
			vis[newmovex][newmovey][newfreex][newfreey]=1;
			++tail;
			Q[tail][0]=newmovex; Q[tail][1]=newmovey;
			Q[tail][2]=newfreex; Q[tail][3]=newfreey;
			dis[newmovex][newmovey][newfreex][newfreey]=dis[movex][movey][freex][freey]+1;
			if(newmovex==TX&&newmovey==TY)return dis[newmovex][newmovey][newfreex][newfreey];
		}
	}
	return -1;
}
int main(){
  freopen("puzzle.in","r",stdin);
  freopen("puzzle.out","w",stdout);
  cin>>n>>m>>q;
  for(i=1;i<=n;i++)
  for(j=1;j<=m;j++)
    scanf("%d",&in[i][j]);
  if(n*m*n*m*q>40000000)bo=1;else bo=0;
  for(i=1;i<=q;i++){
		scanf("%d%d%d%d%d%d",&EX,&EY,&SX,&SY,&TX,&TY);
		if(in[TX][TY])printf("%d\n",BFS());else printf("-1\n");
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}

