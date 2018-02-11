#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#define maxn 40
using namespace std;
bool chess[maxn][maxn];
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int ex,ey,sx,sy,tx,ty;
int n,m,q2;
bool vis[maxn][maxn],check1=false;
struct point{
	int x,y,id;
};
point q[1000];
int head=-1,tail=0;
int work(){
	int ans=0;
   point tmp;head=-1,tail=0;
   tmp.x=ex;tmp.y=ey;tmp.id=0;
   q[0]=tmp;
   
   vis[ex][ey]=true;
   while (head<=tail && !check1){
	   head++;tmp=q[head];
	   int x1=tmp.x,y1=tmp.y,dis=tmp.id;
	   if (x1==tx && y1==ty) {check1=true;ans=ans+dis;break;}
	   for (int i=1;i<=4;i++) {
		  int x2=x1+dx[i],y2=y1+dy[i];
		  if (x2<=0 || x2>n || y2<=0 || y2>m || vis[x2][y2] || !chess[x2][y2]) continue;
		  if (x2==tx && y2==ty) {check1=true;ans=ans+dis+1;break;}
		  tmp.x=x2,tmp.y=y2,tmp.id=dis+1;
		  tail++;q[tail]=tmp;vis[x2][y2]=true;
	   }
   }
  if (check1) {
	head=-1;tail=0;
	chess[ex][ey]=false;
     chess[tx][ty]=true;
     q[0].x=sx;q[0].y=sy;q[0].id=0;
	 bool f=false;
	 memset(vis,false,sizeof(vis));
	 vis[sx][sy]=true;
    while (head<=tail && !f){
		head++;tmp=q[head];
	   int x1=tmp.x,y1=tmp.y,dis=tmp.id;
	   if (x1==tx && y1==ty) {f=false;ans=ans+dis;break;}
	   for (int i=1;i<=4;i++) {
		  int x2=x1+dx[i],y2=y1+dy[i];	
		  if (x2<=0 || x2>n || y2<=0 || y2>m || vis[x2][y2] || !chess[x2][y2]) continue;
		  if (x2==tx && y2==ty) {f=true;ans=ans+dis+1;break;}
		  tmp.x=x2,tmp.y=y2,tmp.id=dis+1;
		  tail++;q[tail]=tmp;vis[x2][y2]=true;
    }
  
  }
  }
  return ans;
}
int main(){
   freopen("puzzle.in","r",stdin);
   freopen("puzzle.out","w",stdout);
   scanf("%d%d%d",&n,&m,&q2);
   int x;
   for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++){
		scanf("%d",&x);
		if (x==0) chess[i][j]=false;
		  else chess[i][j]=true;
     }
   for (int i=1;i<=q2;i++){
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		chess[ex][ey]=true;check1=false;
		memset(vis,false,sizeof(vis));
		int t=work();
		if (check1) printf("%d\n",t);
		  else printf("-1\n");
		chess[ex][ey]=false;
   } 
   fclose(stdin);
   fclose(stdout);
   return 0;
}
