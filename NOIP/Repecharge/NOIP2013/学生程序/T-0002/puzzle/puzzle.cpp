#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int h[4]={-1,0,1,0},l[4]={0,-1,0,1},s[50][50],k=9999,f[50][50][4],ans[505];
int sum,ex,ey,sx,sy,tx,ty,n,m,q;
void found(int x,int y,int z)
{
	int i;
	for(i=0;i<=3;i++)
		if(s[x+h[i]][y+l[i]]!=0&&x+h[i]<=n&&x+h[i]>=1&&y+l[i]<=m&&y+l[i]>=1&&i!=(k-2>0?k-2:2-k)&&f[x][y][i]==0)
		{
			s[x][y]=s[x+h[i]][y+l[i]];
			s[x+h[i]][y+l[i]]=3;
			f[x][y][i]=1;
			if(x==tx&&y==ty&&s[x][y]==2)
			{
				sum=sum<z?sum:z;
				return;
			}
			k=i;
			found(x+h[i],y+l[i],z+1);
			f[x][y][i]=0;
			s[x+h[i]][y+l[i]]=s[x][y];
			s[x][y]=3;
		}
	return ;
}
int main()
{
	int i,j,l=1;
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&s[i][j]);
	for(i=1;i<=q;i++)
	{	
		sum=999999;
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		if(sx==tx&&sy==ty)
		{	
			ans[l]=0;
			l++;
		}
		else
		{	
			s[sx][sy]=2;
			s[ex][ey]=3;	
			found(ex,ey,1);
			if(sum==999999)
			{
				ans[l]=-1;
				l++;
			}
			else
			{
				ans[l]=sum;
				l++;
			}
		}
	}
	for(i=1;i<=q;i++)
	printf("%d\n",ans[i]);
	return 0;
}
