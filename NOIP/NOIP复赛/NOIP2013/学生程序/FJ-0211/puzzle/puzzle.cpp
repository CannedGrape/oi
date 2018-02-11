#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
int map[35][35];
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
int ex,ey,sx,sy,tx,ty;
int n,m,k,x;
int ans;
bool vis[35][35];
void dfs(int x,int y,int t)
{
	vis[x][y]=true;
	if(x==tx && y==ty)
	{	
		for(int i=0;i<=3;i++)
		if(x+dx[i]==sx && y+dy[i]==sy) ans=min(ans,t);
		return;
	}
	int i;
	for(i=0;i<=3;i++)
		if(map[x+dx[i]][y+dy[i]] && !vis[x+dx[i]][y+dy[i]])
		{
			if(sx==x+dx[i] && sy==y+dy[i])
			{
				sx-=dx[i],sy-=dy[i];
				dfs(x+dx[i],y+dy[i],t+1);
				sx+=dx[i],sy+=dy[i];
			}
		    dfs(x+dx[i],y+dy[i],t+1);
		}
}
int main()
{
freopen("puzzle.in","r",stdin);
freopen("puzzle.out","w",stdout);
	cin>>n>>m>>k;
	int i,j;
	for(i=1;i<=n;i++)
	   for(j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	for(i=1;i<=k;i++)
	{
		memset(vis,false,sizeof(vis));
		ans=10000000;
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		dfs(ex,ey,1);
		if(ans==10000000) cout<<"-1\n";
		else cout<<ans<<"\n";
	}
return 0;
}
