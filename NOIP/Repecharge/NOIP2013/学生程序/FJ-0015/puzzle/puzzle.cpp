#include <cstdio>
#define MaxN 35
#define MaxS 850010
#define P 1000007
#define Add(A,B,C,D) view[A][B][C][D]=1;sta[++tot].x1=A;sta[tot].x2=B;sta[tot].x3=C;sta[tot].x4=D;
const int px[4]={-1,0,1,0},
          py[4]={0,1,0,-1};
struct
{
  int x1,x2,x3,x4;
}sta[MaxS],que[MaxS];
int map[MaxN][MaxN],step[MaxS];
int n,m,q,tot,i,j,tx,ty,sx,sy,ex,ey,h,t,nx,ny,nx1,ny1;
bool view[MaxN][MaxN][MaxN][MaxN];
/*inline void Add(int x1,int x2,int x3,int x4)
{
  view[x1][x2][x3][x4]=1;
  sta[++tot].x1=x1;
  sta[tot].x2=x2;
  sta[tot].x3=x3;
  sta[tot].x4=x4;
}*/
inline void PreWork()
{
  for (i=1;i<=tot;++i)
    view[sta[i].x1][sta[i].x2][sta[i].x3][sta[i].x4]=0;
  tot=0;
}
inline void doit()
{
  scanf("%d%d%d%d%d%d",&tx,&ty,&sx,&sy,&ex,&ey);
  //printf("%d %d %d %d %d %d\n",tx,ty,sx,sy,ex,ey);
  if (sx==ex&&sy==ey) {printf("0\n");return;}
  Add(tx,ty,sx,sy);
  que[1].x1=tx; que[1].x2=ty; que[1].x3=sx; que[1].x4=sy; step[1]=0;
  h=0; t=1;
  while (h<t)
  {
    ++h;
    for (i=0;i<=3;++i)
    {
      nx=que[h].x1+px[i]; ny=que[h].x2+py[i];
      if (nx==que[h].x3&&ny==que[h].x4)
      {
        nx1=que[h].x1; ny1=que[h].x2;
      }
      else
      {
        nx1=que[h].x3; ny1=que[h].x4;
      }
      if (map[nx][ny]&&(!view[nx][ny][nx1][ny1]))
      {
        Add(nx,ny,nx1,ny1);
        que[++t].x1=nx; que[t].x2=ny; que[t].x3=nx1; que[t].x4=ny1; step[t]=step[h]+1;
        if (que[t].x3==ex&&que[t].x4==ey) {printf("%d\n",step[t]);return;}
      }
    }
  }
  printf("-1\n");
}
int main()
{
  freopen("puzzle.in","r",stdin);
  freopen("puzzle.out","w",stdout);
  scanf("%d%d%d",&n,&m,&q);
  for (i=1;i<=n;++i)
    for (j=1;j<=m;++j)
      scanf("%d",&map[i][j]);
  for (;q;--q)
  {
    //printf("%d\n",q);
    //Not PreWork
    PreWork();
    doit();
  }
  return 0;
}
