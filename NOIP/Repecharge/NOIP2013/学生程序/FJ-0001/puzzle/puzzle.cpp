#include<cstring>
#include<cstdio>
#define nx searchx[head]
#define ny searchy[head]
#define nsp searchsp[head]
int n,m,q;
int map[35][35],p[35][35][5][5];
int cx[5]={0,1,-1,0,0},cy[5]={0,0,0,1,-1};
int dis[35][35];
int quex[10000],quey[10000],head,tail;
int ex,ey,sx,sy,tx,ty;
int searchx[3600000],searchy[3600000],searchsp[3600000];
int used[35][35][5],distance[35][35][5];
int anti[5]={0,2,1,4,3};
void bfs(int sxx,int syy)
{
	memset(dis,60,sizeof(dis));
	dis[sxx][syy]=0;
	quex[1]=sxx;
	quey[1]=syy;
	head=0;
	tail=1;
	int i;
	while(head<tail)
	{
		++head;
		for(i=1;i<=4;++i)
			if(map[quex[head]+cx[i]][quey[head]+cy[i]]&&dis[quex[head]+cx[i]][quey[head]+cy[i]]>dis[quex[head]][quey[head]]+1)
			{
				dis[quex[head]+cx[i]][quey[head]+cy[i]]=dis[quex[head]][quey[head]]+1;
				quex[++tail]=quex[head]+cx[i];
				quey[tail]=quey[head]+cy[i];
			}
	}
}
void pre(int x,int y)
{
	int i,j;
	for(i=1;i<=4;++i)
		for(j=1;j<=4;++j)
			if(i==j)
				p[x][y][i][j]=0;
			else
				p[x][y][i][j]=1010580540;
	for(i=1;i<=4;++i)
		if(map[x+cx[i]][y+cy[i]])
		{
			bfs(x+cx[i],y+cy[i]);
			for(j=i+1;j<=4;++j)
				p[x][y][i][j]=p[x][y][j][i]=dis[x+cx[j]][y+cy[j]];
		}
}
void solve()
{
	int i,ans=1010580540;
	scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
	map[sx][sy]=0;
	bfs(ex,ey);
	map[sx][sy]=1;
	head=0;
	tail=0;
	memset(distance,60,sizeof(distance));
	memset(used,0,sizeof(used));
	for(i=1;i<=4;++i)
		if(dis[sx+cx[i]][sy+cy[i]]<10000000)
		{
			++tail;
			searchx[tail]=sx;
			searchy[tail]=sy;
			searchsp[tail]=i;
			distance[sx][sy][i]=dis[sx+cx[i]][sy+cy[i]];
			used[sx][sy][i]=1;
		}
	while(head<tail)
	{
		++head;
		for(i=1;i<=4;++i)
			if(distance[nx][ny][i]>distance[nx][ny][nsp]+p[nx][ny][nsp][i])
			{
				distance[nx][ny][i]=distance[nx][ny][nsp]+p[nx][ny][nsp][i];
				if(used[nx][ny][i]==0)
				{
					++tail;
					used[nx][ny][i]=1;
					searchx[tail]=nx;
					searchy[tail]=ny;
					searchsp[tail]=i;
				}
			}
		if(distance[nx+cx[nsp]][ny+cy[nsp]][anti[nsp]]>distance[nx][ny][nsp]+1)
		{
			distance[nx+cx[nsp]][ny+cy[nsp]][anti[nsp]]=distance[nx][ny][nsp]+1;
			if(used[nx+cx[nsp]][ny+cy[nsp]][anti[nsp]]==0)
			{
				++tail;
				used[nx+cx[nsp]][ny+cy[nsp]][anti[nsp]]=1;
				searchx[tail]=nx+cx[nsp];
				searchy[tail]=ny+cy[nsp];
				searchsp[tail]=anti[nsp];
			}
		}
		used[searchx[head]][searchy[head]][searchsp[head]]=0;
	}
	for(i=1;i<=4;++i)
		if(distance[tx][ty][i]<ans)
			ans=distance[tx][ty][i];
	if(ans<1000000)
		printf("%d\n",ans);
	else
		printf("-1\n");
}
int main()
{
	int i,j;
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			scanf("%d",map[i]+j);
	
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(map[i][j])
			{
				map[i][j]=0;
				pre(i,j);
				map[i][j]=1;
			}
	for(i=1;i<=q;++i)
		solve();
	return 0;
}

