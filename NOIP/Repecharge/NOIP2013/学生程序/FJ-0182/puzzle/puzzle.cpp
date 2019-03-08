#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,q,Ex[1001],Ey[1001],Sx[1001],Sy[1001],tx,ty,T[31][31][31][31];
bool a[101][101],f[31][31][31][31];
int get(int x1,int y1,int x2,int y2)
{
	if((x1<1)||(y1<1)||(x1>n)||(y1>m))return -1;
	if((x1==x2)&&(y1==y2))return 0;
	if(!a[x1][y1])return -1;
	int ans=214748,k;
	a[x1][y1]=0;
	k=get(x1+1,y1,x2,y2)+1;
	if(k!=0)ans=min(ans,k);
	k=get(x1-1,y1,x2,y2)+1;
	if(k!=0)ans=min(ans,k);
	k=get(x1,y1+1,x2,y2)+1;
	if(k!=0)ans=min(ans,k);
	k=get(x1,y1-1,x2,y2)+1;
	if(k!=0)ans=min(ans,k);
	a[x1][y1]=1;
	if(ans==214748)return -1;
	return ans;
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)cin>>a[i][j];
	get(1,1,30,30);
	for(int i=1;i<=q;i++)
	{
		cin>>Ex[1]>>Ey[1]>>Sx[1]>>Sy[1]>>tx>>ty;
		bool FL=0;
		int head=1,tail=1;
		memset(f,0,sizeof(f));
		f[Ex[1]][Ey[1]][Sx[1]][Sy[1]]=1;
		T[Ex[1]][Ey[1]][Sx[1]][Sy[1]]=0;
		while(head<=tail)
		{
			int ex=Ex[head],ey=Ey[head],sx=Sx[head],sy=Sy[head];
			head++;
			a[sx][sy]=0;
			if(!f[sx][sy][sx+1][sy])
			{
				int k=get(sx+1,sy,ex,ey);
				if(k!=-1)
				{
					T[sx][sy][sx+1][sy]=T[ex][ey][sx][sy]+k+1;
					if((sx+1==tx)&&(sy==ty)){cout<<T[sx][sy][sx+1][sy]<<endl;FL=true;a[sx][sy]=1;break;}
					f[sx][sy][sx+1][sy]=1;
					tail++;Ex[tail]=sx;Ey[tail]=sy;Sx[tail]=sx+1;Sy[tail]=sy;
				}
			}
			
			if(!f[sx][sy][sx-1][sy])
			{
				int k=get(sx-1,sy,ex,ey);
				if(k!=-1)
				{
					T[sx][sy][sx-1][sy]=T[ex][ey][sx][sy]+k+1;
					if((sx-1==tx)&&(sy==ty)){cout<<T[sx][sy][sx-1][sy]<<endl;FL=true;a[sx][sy]=1;break;}
					f[sx][sy][sx-1][sy]=1;
					tail++;Ex[tail]=sx;Ey[tail]=sy;Sx[tail]=sx-1;Sy[tail]=sy;
				}
			}
			
			if(!f[sx][sy][sx][sy+1])
			{
				int k=get(sx,sy+1,ex,ey);
				if(k!=-1)
				{
					T[sx][sy][sx][sy+1]=T[ex][ey][sx][sy]+k+1;
					if((sx==tx)&&(sy+1==ty)){cout<<T[sx][sy][sx][sy+1]<<endl;FL=true;a[sx][sy]=1;break;}
					f[sx][sy][sx][sy+1]=1;
					tail++;Ex[tail]=sx;Ey[tail]=sy;Sx[tail]=sx;Sy[tail]=sy+1;
				}
			}
			
			if(!f[sx][sy][sx][sy-1])
			{
				int k=get(sx,sy-1,ex,ey);
				if(k!=-1)
				{
					T[sx][sy][sx][sy-1]=T[ex][ey][sx][sy]+k+1;
					if((sx==tx)&&(sy-1==ty)){cout<<T[sx][sy][sx][sy-1]<<endl;FL=true;a[sx][sy]=1;break;}
					f[sx][sy][sx][sy-1]=1;
					tail++;Ex[tail]=sx;Ey[tail]=sy;Sx[tail]=sx;Sy[tail]=sy-1;
				}
			}
			a[sx][sy]=1;
		}
		if(!FL)cout<<-1<<endl;
	}
	return 0;
}

