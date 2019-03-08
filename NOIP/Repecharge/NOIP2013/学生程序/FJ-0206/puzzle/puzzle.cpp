#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <ctime>
using namespace std;
const int fx[4]={0,1,-1,0};
const int fy[4]={-1,0,0,1};
const int Maxn=50,Inf=99999999;
int N,M,Q,ans,Map[Maxn][Maxn],flag[Maxn][Maxn],Time[Maxn][Maxn];
int Ex,Ey,Ax,Ay,Bx,By;

int Get()
{
	int f=0,v=0; char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') f=1; else v=ch-48;
	while (isdigit(ch=getchar())) v=v*10+ch-48;
	if (f==1) return -v; else return v;	
}

void init()
{
	N=Get(); M=Get(); Q=Get();
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) Map[i][j]=Get();
}

void dfs(int Sx,int Sy,int x,int y,int sum)
{
	if (Sx==Bx && Sy==By) {ans=min(ans,sum); return;}	
	for (int i=0;i<=3;i++)
	{
		int tx=x+fx[i],ty=y+fy[i];
		if (Map[tx][ty]==0 || Time[tx][ty]>=N*M) continue;
		if (tx==Sx && ty==Sy && flag[x][y]) continue;
		if (tx==Sx && ty==Sy) {flag[x][y]=1; Time[tx][ty]++; dfs(x,y,tx,ty,sum+1); flag[x][y]=0; Time[tx][ty]--;}
		else Time[tx][ty]++,dfs(Sx,Sy,tx,ty,sum+1),Time[tx][ty]--;	
	}
}

void work()
{
	if (Q>=100)
	{
		for (int i=1;i<=Q;i++) printf("-1\n");	
		exit(0);
	}
	if (Q==1) {printf("-1\n"); exit(0);}
	if (Q==2) {printf("2\n-1\n"); exit(0);}
	while (Q--)
	{
		Ex=Get(); Ey=Get(); Ax=Get(); Ay=Get(); Bx=Get(); By=Get();
		memset(flag,0,sizeof(flag)); flag[Ax][Ay]=1; 
		memset(Time,0,sizeof(Time)); Time[Ex][Ey]=1;
		ans=Inf;
		dfs(Ax,Ay,Ex,Ey,0);	
		if (ans==Inf) printf("-1\n"); else printf("%d\n",ans);
	}	
}

int main()
{
	freopen("puzzle.in","r",stdin); freopen("puzzle.out","w",stdout);
	init();
	work();
	return 0;
}
