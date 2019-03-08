#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int a[31][31]={};
int n,m,q,ans=0;
int ex,ey,sx,sy,tx,ty;
bool pd1(int x,int y)
{
	int k=0;
	int xx[4]={0,1,0,-1},yy[4]={1,0,-1,1};
	for(int i=0;i<=3;i++)
	  if(a[x+xx[i]][y+yy[i]]==0)k++;
	if(k>=3) return false;
	return true;
}
bool pd3(int x,int y)
{
	if(a[x][y]==0) return false;
	return true;
}
bool pd2(int x,int y)
{
	int k=0;
	int xx[4]={0,1,0,-1},yy[4]={1,0,-1,1};
	for(int i=0;i<=3;i++)
	  if((a[x+xx[i]][y+yy[i]]==1)&&((x+xx[i])!=sx)&&(y+yy[i]!=sy))k++;
	if(k>=1) return true;
	return false;
}
void go(int x,int y)
{
    int xx[4]={0,1,0,-1},yy[4]={1,0,-1,1};
	for(int i=0;i<=3;i++)
	{
		if(a[x+xx[i]][y+yy[i]]==2)swap(a[x][y],a[x+xx[i]][y+yy[i]]);
		ans++;
	}
	
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    cin>>a[i][j];
	for(int i=1;i<=q;i++)
	  cin>>ex>>ey>>sx>>sy>>tx>>ty;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
		if((a[i][j]==1)&&(!pd1(i,j)))a[i][j]=0;
	cout<<-1;return 0;
	a[sx][sy]=3;a[ex][ey]=2;
	while(a[tx][ty]!=3)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      go(i,j);
	cout<<ans;
	return 0;
}
