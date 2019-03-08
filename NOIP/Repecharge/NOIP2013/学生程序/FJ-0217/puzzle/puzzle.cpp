#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

const int MAXN=35;

struct node 
{
	int x,y;
};

struct node_a
{
	int x,y;
}a[10];

struct node_q
{
	int bx,by,sx,sy,step;
};

bool g[MAXN][MAXN],f[MAXN][MAXN][MAXN][MAXN];
int n,m,p,ans;
node b,start,target;
bool findanswer;
queue <node_q> q; 

void search()
{
	int i,j,k;
	
	node_q tmp;
	tmp.bx=b.x; tmp.by=b.y;
	tmp.sx=start.x; tmp.sy=start.y;
	tmp.step=0;
	
	q.push(tmp);
	
	while (!q.empty())
	{
		node_q tmp1,tmp2;
		
		tmp1=q.front();
		q.pop();
		if (tmp1.sx==target.x && tmp1.sy==target.y) { findanswer=1; ans=tmp1.step; break;}
		
		for (i=1; i<=4; i++)
		{
			node_a s;
			int xx=tmp1.bx+a[i].x, yy=tmp1.by+a[i].y;  //空格的新位置 
			if (xx>n || xx<1 || yy>m || yy<1) continue;
			if (!g[xx][yy]) continue;
			
			s.x=tmp1.sx; s.y=tmp1.sy;
			if (xx==s.x && yy==s.y) { s.x=tmp1.bx; s.y=tmp1.by; } //起始点的新位置 
		    
			if (!f[xx][yy][s.x][s.y])
			{
				f[xx][yy][s.x][s.y]=1;
				tmp2.bx=xx;
				tmp2.by=yy;
				tmp2.sx=s.x;
				tmp2.sy=s.y;
				tmp2.step=tmp1.step+1;
				q.push(tmp2);
			} 
		}
	}
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	
	int i,j,k;
	
	a[1].x=-1; a[1].y=0;
	a[2].x=0; a[2].y=1;
	a[3].x=1; a[3].y=0;
	a[4].x=0; a[4].y=-1;
	
	scanf("%d%d%d",&n,&m,&p);
	for (i=1; i<=n; i++)
	  for (j=1; j<=m; j++)
	  {
			int x;
			scanf("%d",&x);
			if (x==1) g[i][j]=1;
			else g[i][j]=0;
		}
	
	for (i=1; i<=p; i++)
	{
		scanf("%d%d%d%d%d%d",&b.x,&b.y,&start.x,&start.y,&target.x,&target.y);
		
		memset(f,0,sizeof(f));  // forget......
		ans=0;
		findanswer=0;
		while (!q.empty()) q.pop();
		
		search();
		
		if (findanswer) printf("%d\n",ans);
		else printf("-1\n");
	}
	
	return 0;
}



