#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN=35,MAXP=902;
const int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
int n,m,Q;
int s[MAXN][MAXN];
bool used[MAXN][MAXN][MAXN][MAXN];
int front,rear;
struct Point
{ 
  int x,y;
}kb,qs,mb,qk[MAXP*MAXP],qq[MAXP*MAXP];
int qd[MAXP*MAXP];
int Get()
{ 
  char ch; int sum=0; bool f=false;
  while (!isdigit(ch=getchar()))
    if (ch=='-') f=true;sum=ch-48;
  while (isdigit(ch=getchar())) sum=sum*10+ch-48;
  if (f) return -sum;else return sum;
}
void init()
{ 
  n=Get(),m=Get(),Q=Get();
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) s[i][j]=Get();
}
bool ck(int x,int y,int qx,int qy)
{ 
  if (!(x>=1 && x<=n && y>=1 && y<=m && s[x][y])) return false;
  if (used[x][y][qx][qy]) return false; 
  return true;
}
int bfs()
{ 
  front=1; rear=1;
  used[kb.x][kb.y][qs.x][qs.y]=true; qk[front]=kb; qq[front]=qs; qd[front]=0;
  while (front<=rear)
    {  
       for (int i=0;i<4;i++)  
	    { 
		  int tx=qk[front].x+dx[i],ty=qk[front].y+dy[i],qx=qq[front].x,qy=qq[front].y;
		  if (tx==qq[front].x && ty==qq[front].y) qx=qk[front].x,qy=qk[front].y;
		  if (!ck(tx,ty,qx,qy)) continue;
		  if (qx==mb.x && qy==mb.y) return qd[front]+1;
		  used[tx][ty][qx][qy]=true; rear++; 
		  qk[rear].x=tx; qk[rear].y=ty; qq[rear].x=qx; qq[rear].y=qy; qd[rear]=qd[front]+1;
		}
	  front++;
	}
  return -1;
}
void solve()
{ 
  while (Q--)
    { 
	  kb.x=Get(),kb.y=Get(); qs.x=Get(),qs.y=Get(); mb.x=Get(),mb.y=Get();
      for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
          for (int k=1;k<=n;k++)
            for (int la=1;la<=m;la++) used[i][j][k][la]=false;
	  printf("%d\n",bfs());
	}
}
int main()
{  
  freopen("puzzle.in","r",stdin);
  freopen("puzzle.out","w",stdout);
  init();
  solve();
  return 0;
}
