#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstring>
using namespace std;
inline void read(int &s)
{
	char ch;
	s=0;
	ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
}
int n,m,q,a[40][40],ex,ey,sx,sy,tx,ty,xianzhi=0;
bool flag=false,flag2=false;
bool tepan()
{
	/*if(ex==tx&&ey==ty&&((sx==ex-1&&sy==ey)||(sx==ex+1&&sy==ey)||(sx==ex&&sy==ey+1)||(sx==ex&&sy==ey-1)))
		{printf("1\n");flag2=true;return true;}
	else */
	if((a[tx-1][ty]==0&&a[tx+1][ty]&&a[tx][ty+1])||(a[tx-1][ty]==0&&a[tx+1][ty]&&a[tx][ty+1])||(a[tx-1][ty]==0&&a[tx+1][ty]&&a[tx][ty+1])||(a[tx-1][ty]==0&&a[tx+1][ty]&&a[tx][ty+1]))
		{printf("-1\n");flag2=true;return true;}
	else return false;
}
void dfs(int ccx,int ccy,int x,int y,int step,int maxx)
{
	if(step>maxx||flag)return ;
	if(ccx==tx&&ccy==ty)
	{
		flag=true;
		printf("%d\n",step);
		return ;
	}
	else 
	{
		//if(flag)return ;
		if(a[x+1][y]==1)
			if(ccx==x+1&&ccy==y){
				a[x][y]=0;
				dfs(x,y,x+1,y,step+1,maxx);
				a[x][y]=1;}
			else {
				a[x][y]=0;
				dfs(x,y,x+1,y,step+1,maxx);
				a[x][y]=1;}
		if(a[x-1][y]==1)
			if(ccx==x-1&&ccy==y){
				a[x][y]=0;
				dfs(x,y,x-1,y,step+1,maxx);
				a[x][y]=1;}
			else {
				a[x][y]=0;
				dfs(x,y,x-1,y,step+1,maxx);
				a[x][y]=1;}
		if(a[x][y+1]==1)
			if(ccx==x&&ccy==y+1){
				a[x][y]=0;
				dfs(x,y,x,y+1,step+1,maxx);
				a[x][y]=1;}
			else {
				a[x][y]=0;
				dfs(x,y,x,y+1,step+1,maxx);
				a[x][y]=1;}
		if(a[x][y-1]==1)
			if(ccx==x&&ccy==y-1){
				a[x][y]=0;
				dfs(x,y,x,y-1,step+1,maxx);
				a[x][y]=1;}
			else {
				a[x][y]=0;
				dfs(x,y,x,y-1,step+1,maxx);
				a[x][y]=1;}
		
		
	}
	return ;
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	memset(a,0,sizeof(a));
	read(n);read(m);read(q);
	for(int i=1;i<=n;i++)
	 	for(int j=1;j<=m;j++)
	 		read(a[i][j]);
	for(int i=1;i<=q;i++)
	{
		flag=false;
		flag2=false;
		read(ex);read(ey);read(sx);read(sy);read(tx);read(ty);
		if(flag2==false)
			while(!flag)
			{
				xianzhi++;
				dfs(sx,sy,ex,ey,0,xianzhi);
				if(xianzhi>41990)break;
			}
			if(flag2==false)
				if(!flag)printf("-1\n");
	}
	return 0;
}
