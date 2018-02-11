#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int fx[4]={-1,0,1,0};
const int fy[4]={0,1,0,-1};
int a[101][101],b[101][101];
bool hash[31][31][31][31];
int d[300001][6];
int i,j,k,l,m,n,p,q,x,y,z,bl1,bl2,x1,y1,x2,y2,xx1,xx2,yy1,yy2,xx3,yy3,xx4,yy4,ans,head,tail;
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (i=1; i<=n; i++) for (j=1; j<=m; j++) scanf("%d",&a[i][j]);
	for (z=1; z<=q; z++)
	{
		scanf("%d%d%d%d%d%d",&bl1,&bl2,&x1,&y1,&x2,&y2);
		for (i=1; i<=n; i++) for (j=1; j<=m; j++) b[i][j]=a[i][j];
		memset(d,0,sizeof(d));
		memset(hash,false,sizeof(hash));
		ans=200000000;
		head=0; tail=1;
		d[tail][0]=bl1;
		d[tail][1]=bl2;
		d[tail][2]=x1;
		d[tail][3]=y1;
		d[tail][4]=0;
		while (head<tail)
		{
			head++;
			xx1=d[head][2];//tar
			yy1=d[head][3];
			xx2=d[head][0];//bl
			yy2=d[head][1];
			for (i=0; i<=3; i++)
			{
				xx3=xx2+fx[i];
				yy3=yy2+fy[i];
				if ((xx3==xx1)&&(yy3==yy1))
				{
					xx4=xx2; yy4=yy2;
				} else {xx4=xx1; yy4=yy1;};
				if ((xx4==x2)&&(yy4==y2)){printf("%d\n",d[head][4]+1); goto aaa;};
				if ((xx3>0)&&(xx3<=n)&&(yy3>0)&&(yy3<=m)&&(xx4>0)&&(xx4<=n)&&(yy3>0)&&(yy4<=m)&&(b[xx3][yy3]==1)&&(b[xx4][yy4]==1)&&(hash[xx3][yy3][xx4][yy4]==false))
				{
					tail++;
					d[tail][0]=xx3;
					d[tail][1]=yy3;
					d[tail][2]=xx4;
					d[tail][3]=yy4;
					d[tail][4]=d[head][4]+1;
					hash[xx3][yy3][xx4][yy4]=true;
				}
			}
		}
		printf("-1\n");
		aaa:;
	}
	return 0;
}
