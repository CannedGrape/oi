#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

const int N=32;
int map[N][N];
int gs[N][N];
int n,m,q;
const int ori[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans;
struct Node
{
  int Ex,Ey; //空格位置
  int Sx,Sy; //指定位置
  int step;
}P;
int Tx,Ty; //目标位置
queue<Node> qq;
struct Hash
{
  int Ex,Ey,Sx,Sy;
  int next;
}H[1000],hash[1000001];
int hnum;

int Solve_Hash(Node &p) //求hash值
{
  return (p.Ex+p.Ey+p.Sx*p.Sy);
}

void Ins(int x,Node &p)
{
  hnum++;
  hash[hnum].Ex=p.Ex;
  hash[hnum].Ey=p.Ey;
  hash[hnum].Sx=p.Sx;
  hash[hnum].Sy=p.Sy;
  hash[hnum].next=H[x].next;
  H[x].next=hnum;
}

bool check_hash(Node &p) //判重
{
  int x=Solve_Hash(p);
  for (int i=H[x].next;i!=-1;i=hash[i].next)
    if (hash[i].Ex==p.Ex&&hash[i].Ey==p.Ey&&hash[i].Sx==p.Sx&&hash[i].Sy==p.Sy)
     return 1;
  Ins(x,p);
  return 0;
}

bool Solve_ans()
{
  while (!qq.empty())
  {
    Node tmp=qq.front(); qq.pop();
    if (tmp.Sx==Tx&&tmp.Sy==Ty)
    {
      ans=tmp.step;
      return 1;
    }
    if (gs[tmp.Sx][tmp.Sy]<=1) continue;
    for (int i=0;i<4;i++)
    {
      P=tmp;
      P.step++;
      P.Ex+=ori[i][0]; P.Ey+=ori[i][1];
      if (!map[P.Ex][P.Ey]) continue;
      if (P.Ex==P.Sx&&P.Ey==P.Sy)
      {
        P.Sx=tmp.Ex; P.Sy=tmp.Ey;
      }
      if (check_hash(P)) continue;
      qq.push(P);
    }
  }
  return 0;
}

int main()
{
  freopen("puzzle.in","r",stdin);
  freopen("puzzle.out","w",stdout);
  scanf("%d%d%d",&n,&m,&q);
  for (int i=0;i<=n+1;i++) for (int j=0;j<=m+1;j++) map[i][j]=0;
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
    scanf("%d",&map[i][j]);
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
    gs[i][j]=map[i+1][j]+map[i-1][j]+map[i][j+1]+map[i][j-1];
  while (q--)
  {
    while (!qq.empty()) qq.pop();
    hnum=-1;
    for (int i=0;i<1000;i++) H[i].next=-1;
    scanf("%d%d%d%d%d%d",&P.Ex,&P.Ey,&P.Sx,&P.Sy,&Tx,&Ty);
    if (Tx==P.Sx&&Ty==P.Sy)
    {
      printf("0\n");
      continue;
    }
    if (map[Tx][Ty]==0||gs[Tx][Ty]<=1)
    {
      printf("-1\n");
      continue;
    }
    P.step=0;
    qq.push(P);
    if (Solve_ans()) printf("%d\n",ans); else printf("-1\n");    
  } 
  return 0;
}
