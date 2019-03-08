#include"stdio.h"
#include"string.h"
int q[1100000][4],st[1100000],n,m,i,j,t,qu,a[50][50],vis[32][32][32][32],ex,ey,sx,sy,tx,ty;
int d1[4]={0,1,0,-1},d2[4]={1,0,-1,0},wx,wy,f,head,tail;
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&qu);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(t=1;t<=qu;t++)
	{
		memset(vis,0,sizeof(vis));
		head=1;tail=1;
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		if(a[ex][ey]==0||a[sx][sy]==0||a[tx][ty]==0){printf("-1\n");continue;}
		vis[ex][ey][sx][sy]=1;
		q[1][0]=ex;q[1][1]=ey;q[1][2]=sx;q[1][3]=sy;f=0;
		st[1]=0;
		while(head<=tail)
		{
			if(q[head][2]==tx&&q[head][3]==ty){printf("%d\n",st[head]);f=1;break;}
			for(j=0;j<4;j++)
			{
				wx=q[head][0]+d1[j];
				wy=q[head][1]+d2[j];
				if(a[wx][wy]!=0&&vis[wx][wy][q[head][2]][q[head][3]]==0)
				{
					vis[wx][wy][q[head][2]][q[head][3]]=1;
					tail++;
					q[tail][0]=wx;
					q[tail][1]=wy;
					st[tail]=st[head]+1;
					if(wx==q[head][2]&&wy==q[head][3])
					{
						q[tail][2]=q[head][0];
						q[tail][3]=q[head][1];
					}
					else
					{	
						q[tail][2]=q[head][2];
						q[tail][3]=q[head][3];
					}	
				}
			}
			head++;
		}
		if(f==0)printf("-1\n");
	}
	return 0;
}
					
					
					
					
					
	
