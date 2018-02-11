#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <string.h>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,q,ans,map[40][40],ex,ey,sx,sy,tx,ty,p[40][40];

void dg(int x, int y, int k, int w)
{
	if (k>ans) return;
	if ((x==tx)&&(y==ty))
	  if ((map[x+1][y]==5)||(map[x-1][y]==5)||(map[x][y+1]==5)||(map[x][y-1]==5)) 
	  {
			ans=k; return;
	  }
	//cout <<x << ' ' << y  << ' ' << w<<endl; system("pause");
	if ((w!=1)&&(map[x-1][y]!=0))
		if (map[x-1][y]==5) {map[x-1][y]=1; map[x][y]=5; dg(x-1,y,k+1,3); map[x][y]=1; map[x-1][y]=5;}
		               else dg(x-1,y,k+1,3);
	if ((w!=2)&&(map[x][y+1]!=0))
		if (map[x][y+1]==5) {map[x][y+1]=1; map[x][y]=5; dg(x,y+1,k+1,4); map[x][y]=1; map[x][y+1]=5;}
		               else dg(x,y+1,k+1,4);
	if ((w!=3)&&(map[x+1][y]!=0))
		if (map[x+1][y]==5) {map[x+1][y]=1; map[x][y]=5; dg(x+1,y,k+1,1); map[x][y]=1; map[x+1][y]=5;}
		               else dg(x+1,y,k+1,1);
	if ((w!=4)&&(map[x][y-1]!=0))
		if (map[x][y-1]==5) {map[x][y-1]=1; map[x][y]=5; dg(x,y-1,k+1,2); map[x][y]=1; map[x][y-1]=5;}
		               else dg(x,y-1,k+1,2);
	
}

void pd(int a,int b)
{
	p[a][b]=1; map[a][b]=1;
	if ((map[a+1][b]!=0)&&(p[a+1][b]==0)) pd(a+1,b);
	if ((map[a-1][b]!=0)&&(p[a-1][b]==0)) pd(a-1,b);
	if ((map[a][b+1]!=0)&&(p[a][b+1]==0)) pd(a,b+1);
	if ((map[a][b-1]!=0)&&(p[a][b-1]==0)) pd(a,b-1);
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	memset(map,0,sizeof(map));
	for (int i=1; i<=n; i++)
	  for (int j=1; j<=m; j++)
	    cin >> map[i][j] ;
	
	for (int e=1; e<=q; e++)
	{
		cin >> ex >> ey >> sx >> sy >> tx >> ty;
		//for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (map[i][j]==5) {map[i][j]=1; break;}
		memset(p,0,sizeof(p));
		pd(ex,ey);
		map[sx][sy]=5;
	//	for (int i=1; i<=n
		ans=2000;
		
		
		if ((p[sx][sy]==1)&&(p[tx][ty]==1)) dg(ex,ey,1,0);
		if (ans==2000) ans=-1;
		cout << ans << endl;
	}
	return 0;
}
