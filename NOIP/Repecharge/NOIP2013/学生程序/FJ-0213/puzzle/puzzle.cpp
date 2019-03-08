#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
int n,m,q;
bool map[31][31];
int i,j,k,l,p,x,y;
int ex,ey,sx,sy,tx,ty;
struct node
{
	int ex,ey,qx,qy;
}; 
node que[810001];
int head,tail;
int ans[31][31][31][31];
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	cin>>n>>m>>q;
	for (i=1;i<=n;i++)
	    for (j=1;j<=m;j++)
	    {
			cin>>x;
			if (x==0)map[i][j]=false; else map[i][j]=true;
		}
	for (i=1;i<=q;i++)
	{
		cin>>ex>>ey>>sx>>sy>>tx>>ty;
		for (p=1;p<=n;p++)
		    for (j=1;j<=m;j++)
		        for (k=1;k<=n;k++)
		            for (l=1;l<=m;l++)
		                ans[p][j][k][l]=10000000;
		head=0;
		tail=1;
		que[1].ex=ex;
		que[1].ey=ey;
		que[1].qx=sx;
		que[1].qy=sy;
		ans[ex][ey][sx][sy]=0;
		while (head<tail)
		{
			head++;
			//cout<<que[head].ex<<' '<<que[head].ey<<' '<<que[head].qx<<' '<<que[head].qy<<endl;
			//if ((x==1)and(y==2)and(que[head].qx==1)and(que[head].qy==3)) cout<<ans[1][2][1][3];
			x=que[head].ex; y=que[head].ey;
			if ((x>1)and(map[x-1][y]))
			{
				if ((que[head].qx==x-1)and(que[head].qy==y))
				{
					if (ans[x-1][y][x][y]==10000000)
					{
						ans[x-1][y][x][y]=ans[x][y][x-1][y]+1;				
				        tail++;
				        que[tail].ex=x-1;
				        que[tail].ey=y;
				        que[tail].qx=x;
				        que[tail].qy=y;
				        if ((x==tx)and(y==ty)) break;
				    }
				}else 
				{
				    if (ans[x-1][y][que[head].qx][que[head].qy]==10000000)
					{
						ans[x-1][y][que[head].qx][que[head].qy]=ans[x][y][que[head].qx][que[head].qy]+1;
			            tail++;
			            que[tail].ex=x-1;
			            que[tail].ey=y;
			            que[tail].qx=que[head].qx;
			            que[tail].qy=que[head].qy;
					}
				}
			}
			//if (ans[1][2][1][3]!=10000000) {cout<<1<<endl; break;}
			if ((x<n)and(map[x+1][y]))
			{
				if ((que[head].qx==x+1)and(que[head].qy==y))
				{
					if (ans[x+1][y][x][y]==10000000)
					{
						ans[x+1][y][x][y]=ans[x][y][x+1][y]+1;				
				        tail++;
				        que[tail].ex=x+1;
				        que[tail].ey=y;
				        que[tail].qx=x;
				        que[tail].qy=y;
				        if ((x==tx)and(y==ty)) break;
					}
				}else 
				{
				    if (ans[x+1][y][que[head].qx][que[head].qy]==10000000)
					{
						ans[x+1][y][que[head].qx][que[head].qy]=ans[x][y][que[head].qx][que[head].qy]+1;
			            tail++;
			            que[tail].ex=x+1;
			            que[tail].ey=y;
			            que[tail].qx=que[head].qx;
			            que[tail].qy=que[head].qy;
					}
				}
			}
			//if (ans[1][2][1][3]!=10000000) {cout<<2<<endl; break;}
			if ((y>1)and(map[x][y-1]))
			{
				if ((que[head].qx==x)and(que[head].qy==y-1))
				{
					if (ans[x][y-1][x][y]==10000000)
					{
						ans[x][y-1][x][y]=ans[x][y][x][y-1]+1;				
				        tail++;
				        que[tail].ex=x;
				        que[tail].ey=y-1;
				        que[tail].qx=x;
				        que[tail].qy=y;
				        if ((x==tx)and(y==ty)) break;
					}
				}else 
				{
				    if (ans[x][y-1][que[head].qx][que[head].qy]==10000000)
					{
						ans[x][y-1][que[head].qx][que[head].qy]=ans[x][y][que[head].qx][que[head].qy]+1;
			            tail++;
			            que[tail].ex=x;
			            que[tail].ey=y-1;
			            que[tail].qx=que[head].qx;
			            que[tail].qy=que[head].qy;
					}
				}
			}
			//if (ans[1][2][1][3]!=10000000) {cout<<3<<endl; break;}
			if ((y<m)and(map[x][y+1]))
			{
				if ((que[head].qx==x)and(que[head].qy==y+1))
				{
					if (ans[x][y+1][x][y]==10000000)
					{
						ans[x][y+1][x][y]=ans[x][y][x][y+1]+1;				
				        tail++;
				        que[tail].ex=x;
				        que[tail].ey=y+1;
				        que[tail].qx=x;
				        que[tail].qy=y;
				        if ((x==tx)and(y==ty)) break;
					}
				}else 
				{
				    if (ans[x][y+1][que[head].qx][que[head].qy]==10000000)
					{
						ans[x][y+1][que[head].qx][que[head].qy]=ans[x][y][que[head].qx][que[head].qy]+1;
			            tail++;
			            que[tail].ex=x;
			            que[tail].ey=y+1;
			            que[tail].qx=que[head].qx;
			            que[tail].qy=que[head].qy;
			            
					}
				}
			}
			//if (ans[1][2][1][3]!=10000000) {cout<<4<<endl; break;}
			//if (ans[1][2][1][3]!=10000000){cout<<que[head].ex<<' '<<que[head].ey<<' '<<que[head].qx<<' '<<que[head].qy<<endl;}
		}  
		int ansans=10000000;
		for (j=1;j<=n;j++)
		    for (k=1;k<=m;k++)
		        ansans=min(ansans,ans[j][k][tx][ty]);
		if (ansans==10000000)cout<<-1<<endl; else cout<<ansans<<endl;
	}
}
/*
3 4 2
0 1 1 1
0 1 1 0
0 1 0 0
3 2 1 2 2 2
1 2 2 2 3 2
4 5 2
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
4 3 1 2 3 4
3 4 1 2 4 3
4 4 1
1 1 1 1
1 0 0 1
1 0 0 1
1 1 1 1
4 3 4 4 1 1
*/
