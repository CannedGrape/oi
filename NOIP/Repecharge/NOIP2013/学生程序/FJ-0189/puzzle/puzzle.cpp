#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <cstdlib>
using namespace std;
int w=100007;
int a[100][100],z[5],h[5],n,m,ex,ey,sx,sy,tx,ty,h1[100009];
struct q1
{
	int b[31][31],x,y,st;
}q[5000];
int quickpow(int m,int n)
{
	int ans=1;
	while(n)
	{
		if(n&1) ans=ans%w*m%w;
        n=n>>1;
        m=m%w*m%w;
	}
}
bool panduan(int head,int x,int y)
{
	
	int temp=q[head].b[x][y];
	q[head].b[x][y]=2;
	q[head].b[q[head].x][q[head].y]=temp;
	int t=0,sum=0;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  {
			t++;
			sum=sum+q[head].b[i][j]*quickpow(7,t);
	  }
	if(h1[sum]==1)
			return false;
	else 
	{h[sum]=1;return true;
	}
}
int bfs(int x,int y,int x2,int y2,int x1,int y1)
{
	
	int head=1,tail=1;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	 q[head].b[i][j]=a[i][j];
	q[head].x=x;
	q[head].y=y;
	while(head<=tail)
	{
		for(int i=1;i<=4;i++)
		if(q[head].x+z[i]<=n&&q[head].x+z[i]>0&&q[head].y+h[i]>0&&q[head].y+h[i]<=m&&a[q[head].x+z[i]][q[head].y+h[i]]!=0)
		{
		if(panduan(head,q[head].x+z[i],q[head].y+h[i]))
		{		
			tail++;
			q[tail]=q[head];
			int temp;
			temp=q[tail].b[q[tail].x+z[i]][q[tail].y+h[i]];
			q[tail].b[q[tail].x+z[i]][q[tail].y+h[i]]=q[tail].b[q[tail].x][q[tail].y];
			q[tail].b[q[tail].x][q[tail].y]=temp;
			q[tail].x+=z[i];
			q[tail].y+=h[i];
			q[tail].st=q[head].st+1;
			if(q[tail].b[x1][y1]==3) return q[tail].st;
		}
	   }
		head++;
	}
	return -1;
}
void me()
{
		for(int i=1;i<=5000;i++)
		 {
				memset(q[i].b,0,sizeof(q[i].b));
				q[i].x=0;
				q[i].y=0;
		 }	
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
    int q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>a[i][j];
	  z[1]=0;z[2]=1;z[3]=0;z[4]=-1;
	  h[1]=1;h[2]=0;h[3]=-1;h[4]=0;
	for(int i=1;i<=q;i++)
	 {
		cin>>ex>>ey>>sx>>sy>>tx>>ty;
		memset(h1,0,sizeof(h1));
		me();
		int temp1=a[ex][ey];
		int temp2=a[sx][sy];
		int temp3=a[tx][ty];
		if(a[ex][ey]!=0)a[ex][ey]=2;
		else {cout<<-1<<endl;continue;}
		if(a[sx][sy]!=0)a[sx][sy]=3;
		else {cout<<-1<<endl;continue;}
		if(a[tx][ty]==0) {cout<<-1<<endl;continue;}
		cout<<bfs(ex,ey,sx,sy,tx,ty)<<endl;
		a[ex][ey]=temp1;
		a[sx][sy]=temp2;
		a[tx][ty]=temp3;
	 }
	 return 0;
}
