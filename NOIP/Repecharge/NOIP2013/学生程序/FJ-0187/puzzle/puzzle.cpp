#include <iostream>
#include <cstdio>
using namespace std;
int n,m,q;
int map[35][35],ex,ey,sx,sy,tx,ty,ans,sum;
int v1[35][35],v2[32][32][32][32];
void work1(int kx,int ky,int bx,int by,int s)
{
	if(kx==bx && ky==by) return;
	if(map[kx-1][ky]==1 && kx-1>0 && s+1<v1[kx-1][ky]) 
	{v1[kx-1][ky]=s+1; work1(kx-1,ky,bx,by,s+1);}
	if(map[kx+1][ky]==1 && kx+1<=n && s+1<v1[kx+1][ky]) 
	{v1[kx+1][ky]=s+1;work1(kx+1,ky,bx,by,s+1);}
	if(map[kx][ky-1]==1 && ky-1>0 && s+1<v1[kx][ky-1]) 
	{v1[kx][ky-1]=s+1;work1(kx,ky-1,bx,by,s+1);}
	if(map[kx][ky+1]==1 && ky+1<=m && s+1<v1[kx][ky+1]) 
	{
	v1[kx][ky+1]=s+1;work1(kx,ky+1,bx,by,s+1);}
	return;
}
void work2(int kx,int ky,int bx,int by,int s)
{
	if(bx==tx && by==ty)  sum=min(sum,s);
	if(map[kx-1][ky]==1 && kx-1>0 && s+1<v2[kx-1][ky][bx][by])
	{v2[kx-1][ky][bx][by]=s+1;if(kx-1==bx && ky==by) work2(bx,by,kx,ky,s+1);else work2(kx-1,ky,bx,by,s+1);}
	
	if(map[kx+1][ky]==1 && kx+1<=n && s+1<v2[kx+1][ky][bx][by])
	{v2[kx+1][ky][bx][by]=s+1;if(kx+1==bx && ky==by) work2(bx,by,kx,ky,s+1);else work2(kx+1,ky,bx,by,s+1);}
	
	if(map[kx][ky-1]==1 && ky-1>0 && s+1<v2[kx][ky-1][bx][by])
	{v2[kx][ky-1][bx][by]=s+1;if(kx==bx && ky-1==by) work2(bx,by,kx,ky,s+1);else work2(kx,ky-1,bx,by,s+1);}
	
	if(map[kx][ky+1]==1 && ky+1<=m && s+1<v2[kx][ky+1][bx][by])
	{v2[kx][ky+1][bx][by]=s+1;if(kx==bx && ky+1==by) work2(bx,by,kx,ky,s+1);else work2(kx,ky+1,bx,by,s+1);}
	
	return;
}
int main()
{	
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int i,j,z,x,y;
	cin>>n>>m>>q;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {scanf("%d",&map[i][j]);}
    for(i=1;i<=q;i++)
    {
	for(j=1;j<=n;j++) for(z=1;z<=m;z++) v1[j][z]=100000000;
	ans=100000000;
	scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
	if(sx==tx && sy==ty) cout<<0<<endl;
    else 
	  {
		v1[ex][ey]=0;
	   work1(ex,ey,sx,sy,0);
        if(v1[sx+1][sy]==100000000 && v1[sx-1][sy]==100000000 && v1[sx][sy+1]==100000000 && v1[sx][sy-1]==100000000) cout<<-1<<endl;
        else {
			  if(v1[sx+1][sy]!=100000000 && sx+1<=n) 
			  {
					for(j=1;j<=n;j++)for(z=1;z<=m;z++)for(x=1;x<=n;x++)for(y=1;y<=m;y++) v2[j][z][x][y]=100000000;
					sum=100000000,work2(sx+1,sy,sx,sy,0);if(sum!=100000000) ans=min(ans,sum+v1[sx+1][sy]);
			  }
			 
			  
			  if(v1[sx-1][sy]!=100000000 && sx-1>0) 
			  {
					for(j=1;j<=n;j++)for(z=1;z<=m;z++)for(x=1;x<=n;x++)for(y=1;y<=m;y++) v2[j][z][x][y]=100000000;
					sum=100000000,work2(sx-1,sy,sx,sy,0);if(sum!=100000000) ans=min(ans,sum+v1[sx-1][sy]);
			  }
			 
			  
			  if(v1[sx][sy+1]!=100000000 && sy+1<=m) 
			  {
					for(j=1;j<=n;j++)for(z=1;z<=m;z++)for(x=1;x<=n;x++)for(y=1;y<=m;y++) v2[j][z][x][y]=100000000;
					sum=100000000,work2(sx,sy+1,sx,sy,0);if(sum!=100000000) ans=min(ans,sum+v1[sx][sy+1]);
			  }
			  
			  
			  if(v1[sx][sy-1]!=100000000 && sy-1>0) 
			  {
					for(j=1;j<=n;j++)for(z=1;z<=m;z++)for(x=1;x<=n;x++)for(y=1;y<=m;y++) v2[j][z][x][y]=100000000;
					sum=100000000,work2(sx,sy-1,sx,sy,0);if(sum!=100000000) ans=min(ans,sum+v1[sx][sy-1]);
			  }
			 
			  if(ans!=100000000) cout<<ans<<endl;
			  else cout<<-1<<endl;
	          }
	  }
	}
    return 0;
}
