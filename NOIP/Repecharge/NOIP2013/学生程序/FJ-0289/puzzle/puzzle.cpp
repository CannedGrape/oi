#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int dx[5]={0,0,0,1,-1};
const int dy[5]={0,1,-1,0,0};
struct xx{
  int x,y,x1,y1,e;
}q[5000001];
int n,m,k,a[31][31],ex,ey,sx,sy,tx,ty,ans;
bool p[31][31][5],s;
int bfs(){
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) 
	for (int k=1;k<=4;k++) p[i][j][k]=false;
    q[1].x=ex;q[1].y=ey;q[1].x1=sx;q[1].y1=sy; q[1].e=0;
    int head=0,tail=1,h=0;
    while (head<=tail)
     {
	    head++;		
	    int l=q[head].x,r=q[head].y;
	    for (int i=1;i<=4;i++)
	     {
		   int p1=dx[i]+l,p2=dy[i]+r;
		   if (p1>=1&&p1<=n&&p2>=1&&p2<=m)
		   if (a[p1][p2]!=0&&!p[p1][p2][i])
		    {
		      tail++;
		      p[p1][p2][i]=true;
		      if (q[head].x1==p1&&q[head].y1==p2)
		        {
				  q[tail].x=p1; q[tail].y=p2;
				  q[tail].x1=q[head].x; q[tail].y1=q[head].y;
				  q[tail].e=q[head].e+1;
				}
			  else
			    {
				  q[tail].x=p1; q[tail].y=p2;
				  q[tail].x1=q[head].x1; q[tail].y1=q[head].y1;
				  q[tail].e=q[head].e+1;
				}
			  if (q[tail].x1==tx&&q[tail].y1==ty)
			   {
			     h=q[tail].e;
			     s=true;
			   }
		    }
		 }
	   if (s) break;
	 }
	return(h);
}
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	  scanf("%d%d%d",&n,&m,&k);
	  for (int i=1;i<=n;i++)
	   for (int j=1;j<=m;j++)
		  scanf("%d",&a[i][j]);
	  for (int i=1;i<=k;i++)
	   {
	      scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
	      s=false;
		  ans=bfs();
		  if (s) printf("%d\n",ans);
		  else printf("-1");
	   }
	fclose(stdin);fclose(stdout);
}
