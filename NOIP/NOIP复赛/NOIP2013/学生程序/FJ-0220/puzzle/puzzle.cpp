#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int i,j,k,l,x,y,m,n,a[100][100]={},q,ex,ey,sx,sy,tx,ty,f[40][40][900],b[100][100],ans;
int js(int a,int b,int c,int d)
{
	return ((a*3+b)*3+c)*3+d;
}
int suan(int a,int b,int c,int d)
{
	if (a==2||b==2||c==2||d==2) return 1;else return 0;
}
void dg(int x,int y,int c)
{
	if  (x==tx&&y==ty&&suan(a[x-1][y],a[x+1][y],a[x][y-1],a[x][y+1])==1) 
	{
		ans=min(ans,c+1);
		return;
	}
	int k=js(a[x-1][y],a[x+1][y],a[x][y-1],a[x][y+1]);
	if (f[x][y][k]>=0) return;else f[x][y][k]=c;
	if (c>ans) return;
	if  (a[x-1][y]!=0) 
	   {a[x][y]=a[x-1][y];a[x-1][y]=3;dg(x-1,y,c+1);a[x-1][y]=a[x][y];a[x][y]=3;}
	if  (a[x+1][y]!=0) 
	   {a[x][y]=a[x+1][y];a[x+1][y]=3;dg(x+1,y,c+1);a[x+1][y]=a[x][y];a[x][y]=3;}
	if  (a[x][y-1]!=0) 
	   {a[x][y]=a[x][y-1];a[x][y-1]=3;dg(x,y-1,c+1);a[x][y-1]=a[x][y];a[x][y]=3;}
	if  (a[x][y+1]!=0) 
	   {a[x][y]=a[x][y+1];a[x][y+1]=3;dg(x,y+1,c+1);a[x][y+1]=a[x][y];a[x][y]=3;}
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for (i=1;i<=n;i++)
	    for (j=1;j<=m;j++)
	        cin>>a[i][j];
	for (i=1;i<=q;i++)
	{
		memset(f,-1,sizeof(f));ans=1000000000;
		cin>>ex>>ey>>sx>>sy>>tx>>ty;
		a[ex][ey]=3;a[sx][sy]=2;
		dg(ex,ey,0);
		if (ans!=1000000000)cout<<ans<<endl;else cout<<-1<<endl;
		for (j=1;j<=n;j++)
			for (k=1;k<=m;k++)
				if (a[j][k]>1) a[j][k]=1;
	}
	return 0;
}
