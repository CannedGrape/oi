#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
const int Maxn=32,Maxp=980208;
const int fx[4]={1,-1,0,0},fy[4]={0,0,1,-1};
int n,m,q;
bool map[Maxn][Maxn];
int get()
{
	int f=0,v=0;char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') f=1;else v=ch-48;
	while (isdigit(ch=getchar())) v=v*10+ch-48;
	if (f) return -v;else return v;
}
int Qx[Maxp],Qy[Maxp],EX[Maxp],EY[Maxp];
int Dist[Maxn][Maxn][Maxn][Maxn];
int t[Maxn][Maxn][Maxn][Maxn],Time=0;
void work(int Ex,int Ey,int Sx,int Sy,int Tx,int Ty)
{
	Time++;
	t[Sx][Sy][Ex][Ey]=Time;Dist[Sx][Sy][Ex][Ey]=0;
	int l=1,r=2;Qx[1]=Sx;Qy[1]=Sy;EX[1]=Ex;EY[1]=Ey;
	while (l!=r)
	{
		for (int k=0;k<=3;k++)
		{
			int x=EX[l]+fx[k],y=EY[l]+fy[k],x2=Qx[l],y2=Qy[l];
			if (map[x][y]) continue;
			if (x2==x&&y2==y) x2=EX[l],y2=EY[l];
			if (t[x2][y2][x][y]==Time) continue;
			t[x2][y2][x][y]=Time;
			Dist[x2][y2][x][y]=Dist[Qx[l]][Qy[l]][EX[l]][EY[l]]+1;
			if (x2==Tx&&y2==Ty) {printf("%d\n",Dist[x2][y2][x][y]);return;}
			Qx[r]=x2;Qy[r]=y2;EX[r]=x;EY[r]=y;
			r++;
		}
		l++;
	}
	printf("-1\n");
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	n=get();m=get();q=get();
	for (int i=1;i<=n;i++) map[i][0]=map[i][m+1]=true;
	for (int j=1;j<=m;j++) map[0][j]=map[n+1][j]=true;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			map[i][j]=1-get();
		}
	for (int i=1;i<=q;i++)
	{
		int Ex=get(),Ey=get(),Sx=get(),Sy=get(),Tx=get(),Ty=get();
		if (Sx==Tx&&Sy==Ty) {printf("0\n");continue;}
		if (map[Sx][Sy]||map[Tx][Ty]) {printf("-1\n");continue;}
		work(Ex,Ey,Sx,Sy,Tx,Ty);
	}
	return 0;
}
