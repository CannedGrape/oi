#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define maxn 35
using namespace std;
struct node
{
	int x,y;
};
struct node2
{
	int x,y,num;
};
queue <node2>P;
node2 stack[maxn*maxn];
int top;
int N,M,Q;
int G[maxn][maxn];
bool vis[maxn][maxn];
int EX,EY,SX,SY,TX,TY;
int BX,BY;
const int XL[4]={1,-1,0,0};
const int YL[4]={0,0,1,-1};
int BFS(int X,int Y,int QX,int QY,int nX,int nY)
{
	while (!P.empty()) P.pop();
	node2 now;
	now.x=X;now.y=Y;now.num=0;
	P.push(now);
	while (!P.empty())
	{
		//if (P.size()>900) return -1;
		now=P.front();
			//printf("(%d %d %d)\n",now.x,now.y,now.num);
		if (now.x==nX&&now.y==nY) return now.num;
		int i;
		for (i=0;i<=3;i++)
		{
			node2 TJ;
			TJ.x=now.x+XL[i];
			TJ.y=now.y+YL[i];
			TJ.num=now.num+1;
			//printf("(%d %d %d %d %d)\n",TJ.x,TJ.y,TJ.num,QX,QY);
			if (G[TJ.x][TJ.y]&&(TJ.x!=QX||TJ.y!=QY)) P.push(TJ);
	    }
	    P.pop();
    }
}
int maxans=999999999;
void dfs(int X,int Y)
{
	stack[++top].x=X;stack[top].y=Y;
	if (X==TX&&Y==TY)
	{
		int i,ans=0;
		//for (i=1;i<=top;i++) printf("[%d %d]",stack[i].x,stack[i].y);printf("%d\n",top);
		BX=EX;BY=EY;
		for (i=2;i<=top;i++)
		{
			int ss=BFS(BX,BY,stack[i-1].x,stack[i-1].y,stack[i].x,stack[i].y);
			if (ss!=-1) ans+=ss ;
			else return;
			ans++;
			BX=stack[i-1].x;BY=stack[i-1].y;
	    }
	    //printf("[%d]\n",ans);system("pause");
	    //printf("%d\n",P.size());
	    maxans=min(maxans,ans);
		top--;
		return;
    }
    vis[X][Y]=true;
    if (G[X-1][Y]&&(!vis[X-1][Y]))  dfs(X-1,Y);
    if (G[X+1][Y]&&(!vis[X+1][Y]))  dfs(X+1,Y);
    if (G[X][Y-1]&&(!vis[X][Y-1]))  dfs(X,Y-1);
    if (G[X][Y+1]&&(!vis[X][Y+1]))  dfs(X,Y+1);
    vis[X][Y]=false;
    top--;
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&N,&M,&Q);
	memset(G,0,sizeof(G));
	int i,j,k;
	for (i=1;i<=N;i++)
	for (j=1;j<=M;j++) scanf("%d",&G[i][j]);
	for (k=1;k<=Q;k++)
	{
		while (!P.empty()) P.pop();
		memset(stack,0,sizeof(stack));
		memset(vis,0,sizeof(vis));
		top=0;
		scanf("%d%d%d%d%d%d",&EX,&EY,&SX,&SY,&TX,&TY);
		dfs(SX,SY);
		printf("%d\n",maxans);
    }
}
