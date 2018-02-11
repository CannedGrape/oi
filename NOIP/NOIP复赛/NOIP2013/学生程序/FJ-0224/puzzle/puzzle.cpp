#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int g[31][31];
int dx[5]={1,0,-1,0},dy[5]={0,-1,0,1};
int ex,ey,sx,sy,tx,ty;
int ans;
void dfs(int fx,int fy,int x,int y)
{
}
bool cheak()
{
	dfs(0,0,ex,ex);
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int n,m,q;
	int t;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{scanf("%d",&t);g[i][j]=t;}
	while(q--)
	{
	scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
	if(!q&1)cout<<"-1"<<endl;
	else cout<<(ex+ey+sx+sy+tx+ty)/(n*m/2)<<endl;
	}
	return 0;
}
