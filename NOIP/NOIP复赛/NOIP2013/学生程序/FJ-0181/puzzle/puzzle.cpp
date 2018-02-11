#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,q;
int vis[31][31][31][31];
int map[32][32];
struct edge
{
	int block_x,block_y,now_x,now_y;
}que[1000000];
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int i,j,k;
	scanf("%d%d%d",&n,&m,&q);
	memset(map,0,sizeof(map));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	while(q--)
	{
		int end_x,end_y;
		int block_x,block_y;
		int now_x,now_y;
		int first,last;
		int ans;
		scanf("%d%d%d%d%d%d",&block_x,&block_y,&now_x,&now_y,&end_x,&end_y);
		memset(vis,-1,sizeof(vis));
		if ((now_x==end_x) && (now_y=end_y))
		{
			cout<<"0"<<endl;
		}
		else if ((block_x==now_x)&&(block_y==now_y))
		{
			cout<<"-1"<<endl;
		}
		else if (map[now_x][now_y]==0)
		{
			cout<<"-1"<<endl;
		}
		else if (map[block_x][block_y]==0)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			que[1].block_x=block_x;
			que[1].block_y=block_y;
			que[1].now_x=now_x;
			que[1].now_y=now_y;
			vis[now_x][now_y][block_x][block_y]=0;
			first=1;
			last=1;
			ans=-1;
			while (first<=last)
			{
				block_x=que[first].block_x;
				block_y=que[first].block_y;
				now_x=que[first].now_x;
				now_y=que[first].now_y;
				if (map[block_x+1][block_y]==1)
				{
					if(now_x==block_x+1 && now_y==block_y)
					{
						if (vis[now_x-1][now_y][block_x+1][block_y]==-1)
						{
							last++;
							que[last].block_x=block_x+1;
							que[last].block_y=block_y;
							que[last].now_x=now_x-1;
							que[last].now_y=now_y;
							vis[now_x-1][now_y][block_x+1][block_y]=vis[now_x][now_y][block_x][block_y]+1;
							if((now_x-1==end_x)&&(now_y==end_y))
							{
								ans=vis[now_x-1][now_y][block_x+1][block_y];
								break;
							}
						}
					}
					else
					{
						if(vis[now_x][now_y][block_x+1][block_y]==-1)
						{
							last++;
							que[last].block_x=block_x+1;
							que[last].block_y=block_y;
							que[last].now_x=now_x;
							que[last].now_y=now_y;
							vis[now_x][now_y][block_x+1][block_y]=vis[now_x][now_y][block_x][block_y]+1;
						}
					}
				}
				if (map[block_x-1][block_y]==1)
				{
					if(now_x==block_x-1 && now_y==block_y)
					{
						if (vis[now_x+1][now_y][block_x-1][block_y]==-1)
						{
							last++;
							que[last].block_x=block_x-1;
							que[last].block_y=block_y;
							que[last].now_x=now_x+1;
							que[last].now_y=now_y;
							vis[now_x+1][now_y][block_x-1][block_y]=vis[now_x][now_y][block_x][block_y]+1;
							if((now_x+1==end_x)&&(now_y==end_y))
							{
								ans=vis[now_x+1][now_y][block_x-1][block_y];
								break;
							}
						}
					}
					else
					{
						
						if(vis[now_x][now_y][block_x-1][block_y]==-1)
						{
							last++;
							que[last].block_x=block_x-1;
							que[last].block_y=block_y;
							que[last].now_x=now_x;
							que[last].now_y=now_y;
							vis[now_x][now_y][block_x-1][block_y]=vis[now_x][now_y][block_x][block_y]+1;
						}
					}
				}
				if (map[block_x][block_y+1]==1)
				{
					if(now_x==block_x && now_y==block_y+1)
					{
						if (vis[now_x][now_y-1][block_x][block_y+1]==-1)
						{
							last++;
							que[last].block_x=block_x;
							que[last].block_y=block_y+1;
							que[last].now_x=now_x;
							que[last].now_y=now_y-1;
							vis[now_x][now_y-1][block_x][block_y+1]=vis[now_x][now_y][block_x][block_y]+1;
							if((now_x==end_x)&&(now_y-1==end_y))
							{
								ans=vis[now_x][now_y-1][block_x][block_y+1];
								break;
							}
						}
					}
					else
					{
						if(vis[now_x][now_y][block_x][block_y+1]==-1)
						{
							last++;
							que[last].block_x=block_x;
							que[last].block_y=block_y+1;
							que[last].now_x=now_x;
							que[last].now_y=now_y;
							vis[now_x][now_y][block_x][block_y+1]=vis[now_x][now_y][block_x][block_y]+1;
						}
					}
				}
				if (map[block_x][block_y-1]==1)
				{
					if(now_x==block_x && now_y==block_y-1)
					{
						if (vis[now_x][now_y+1][block_x][block_y-1]==-1)
						{
							last++;
							que[last].block_x=block_x;
							que[last].block_y=block_y-1;
							que[last].now_x=now_x;
							que[last].now_y=now_y+1;
							vis[now_x][now_y+1][block_x][block_y-1]=vis[now_x][now_y][block_x][block_y]+1;
							if((now_x==end_x)&&(now_y+1==end_y))
							{
								ans=vis[now_x][now_y+1][block_x][block_y-1];
								break;
							}
						}
					}
					else
					{
						if(vis[now_x][now_y][block_x][block_y-1]==-1)
						{
							last++;
							que[last].block_x=block_x;
							que[last].block_y=block_y-1;
							que[last].now_x=now_x;
							que[last].now_y=now_y;
							vis[now_x][now_y][block_x][block_y-1]=vis[now_x][now_y][block_x][block_y]+1;
						}
					}
				}
				first++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
