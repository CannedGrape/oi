#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int fx[4]={-1,0,0,1},fy[4]={0,1,-1,0};
struct Data{int x1,y1,x2,y2;}q[810005];
int n,m,Q,ans[31][31][31][31];
bool map[31][31];
int get()
{
	int res=0,v=0;char ch;
	while (!isdigit(ch=getchar())) if (ch=='-')break;
	if (ch=='-') v=1;else res=ch-48;
	while (isdigit(ch=getchar())) res=res*10+ch-48;
	if (v) return -res;return res;
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	int i,j,k,EX,EY,SX,SY,TX,TY;
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++) map[i][j]=get(),map[i][j]=!map[i][j];
	while (Q--)
	{
	  EX=get(),EY=get(),SX=get(),SY=get(),TX=get(),TY=get();
	  if (SX==TX&&SY==TY) {printf("0\n");continue;}
	  memset(ans,-1,sizeof(ans));
	  ans[EX][EY][SX][SY]=0;
	  q[1]=(Data){EX,EY,SX,SY};
	  int l=1,r=2,flag=0,res=0,x1,y1,x2,y2;
	  while (l<r&&!flag)
	  {
		for (k=0;k<4;k++)
		{
		  x1=q[l].x1+fx[k];y1=q[l].y1+fy[k];
		  if (x1==q[l].x2&&y1==q[l].y2) x2=q[l].x1,y2=q[l].y1;  
		  else x2=q[l].x2,y2=q[l].y2;
		  if (x1<1||y1<1||x2<1||y2<1||x1>n||x2>n||y1>m||y2>m) continue;
		  if (map[x1][y1]||map[x2][y2]) continue;
		  if (ans[x1][y1][x2][y2]!=-1) continue;
		  ans[x1][y1][x2][y2]=ans[q[l].x1][q[l].y1][q[l].x2][q[l].y2]+1;
		  if (x2==TX&&y2==TY)
		  {
		    flag=1,res=ans[x1][y1][x2][y2];
		    break;
		  }
		  q[r++]=(Data){x1,y1,x2,y2};
		}l++;
	  }
	  if (flag) printf("%d\n",res);
	  else printf("-1\n");
	}
	return 0;
}
