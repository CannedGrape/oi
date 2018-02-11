#include <cstdio>
#include <algorithm>

using namespace std;


int n,m,q;
bool map[31][31];
int on[31][31][31][31];
int mark;
int spaceX,spaceY,startX,startY,endX,endY;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};



int b[1000000][5];
int bfs()
{
	if (startX==endX && startY==endY) return(0);
	
	int l=1,r=1;
	b[l][0]=startX;
	b[l][1]=startY;
	b[l][2]=spaceX;
	b[l][3]=spaceY;
	b[l][4]=0;
	
	on[startX][startY][spaceX][spaceY]=mark;
	
	for(;l<=r;l++)
	{
		int x0=b[l][2],y0=b[l][3];
		for (int i=0;i<4;i++)
		{
			int x1=x0+dx[i],y1=y0+dy[i];
			if (!map[x1][y1] || x1<=0 || y1<=0 || x1>n || y1>m) continue;
			
			int x2=b[l][0],y2=b[l][1];
			if (x1==x2 && y1==y2)
			{
				if (on[x0][y0][x2][y2]!=mark)
				{
					on[x0][y0][x2][y2]=mark;
					if (x0==endX && y0==endY) return(b[l][4]+1);
					r++;
					b[r][0]=x0;
					b[r][1]=y0;
					b[r][2]=x2;
					b[r][3]=y2;
					b[r][4]=b[l][4]+1;
				}
			}
			else
			{
				if (on[x2][y2][x1][y1]!=mark)
				{
					on[x2][y2][x1][y1]=mark;
					r++;
					b[r][0]=x2;
					b[r][1]=y2;
					b[r][2]=x1;
					b[r][3]=y1;
					b[r][4]=b[l][4]+1;
				}
			}
		}
	}
	
	return(-1);
}



int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			int s;
			scanf("%d",&s);
			map[i][j]=s;
		}
	}
	
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d%d%d",&spaceX,&spaceY,&startX,&startY,&endX,&endY);
		mark=i;
		int s=bfs();
		printf("%d\n",s);
	}
	return(0);
}

