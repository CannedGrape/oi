#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=33,inf=2111111111;
const int xd[4]={-1,0,1,0};
const int yd[4]={0,-1,0,1};
int map[maxn][maxn],N,M,Q,Ex,Ey,Sx,Sy,Tx,Ty,ans;
bool finde,findt,finds;
int get(){
    int v=0,f=0; char ch;
    while (!isdigit(ch=getchar())) if (ch=='-') break;
    if (ch=='-') f=1; else v=ch-48;
    while (isdigit(ch=getchar())) v=v*10+ch-48;
    if (f) return -v; else return v;
}
void init(){
    N=get(); M=get();Q=get();
    for (int i=1;i<=N;i++){
	    for (int j=1;j<=M;j++){
		    map[i][j]=get();
		}
	}
}
void dfs(int x,int y,int cnt,int fx,int fy){
    if ((finds&&x==Tx&&y==Ty&&(Sx!=fx&&Sy!=fy))||(findt&&x==Sx&&y==Sy)){
	    ans=min(ans,cnt); return;
	}
	if (x==Sx&&y==Sy) finds=1;
	if (x==Tx&&y==Ty) findt=1;
	if (cnt>20000){
		finde=1; 
		return;
	}
	for (int i=0;i<4;i++){
	    int xx=x+xd[i],yy=y+yd[i];
		if (xx>0&&xx<=N&&yy>0&&yy<=M&&(xx!=fx||yy!=fy)&&map[xx][yy]&&!finde)
		dfs(xx,yy,cnt+1,x,y);
	}
	if (x==Sx&&y==Sy) finds=0;
	if (x==Tx&&y==Ty) findt=0;
}
void work(){
    for (int i=1;i<=Q;i++){
		ans=inf; finds=0; findt=0; finde=0;
	    Ex=get(); Ey=get();Sx=get(); Sy=get();Tx=get();Ty=get();
	    dfs(Ex,Ey,0,0,0);
	    if (ans!=inf)printf("%d\n",ans);
	    else printf("-1\n");
	}
}
int main(){
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    work();
    return 0;
}
