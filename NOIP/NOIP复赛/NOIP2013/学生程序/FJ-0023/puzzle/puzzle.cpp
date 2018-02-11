#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,qu;
int ex,ey,sx,sy,tx,ty;
int move[4][4]={{1,0},{0,1},{-1,0},{0,-1}};
int q[5000001][5],head,tail;
bool a[31][31];
bool vis[31][31][31][31];

void file_open()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
}

void file_close()
{
    fclose(stdin); fclose(stdout);
}

int init()
{
    int x;
    cin>>n>>m>>qu;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        {
          scanf("%d",&x);
          a[i][j]=x;
        }
    return 0;
}

int bfs()
{
    int xx,yy;
    if (sx==tx && sy==ty) 
    {
      cout<<0<<endl;
      return 0;
    }
    head=0,tail=1;
    q[1][0]=ex; q[1][1]=ey; q[1][2]=sx; q[1][3]=sy; q[1][4]=0;
    do
    {
      head++;
      if (head>5000000) head=1;
      for (int i=0;i<=3;i++)
      {
        xx=q[head][0]+move[i][0];
        yy=q[head][1]+move[i][1];
        if (xx>0 && xx<=n && yy>0 && yy<=m)
        {
          if (a[xx][yy])
          {
            if (xx==q[head][2] && yy==q[head][3])
            {
              if (q[head][0]==tx && q[head][1]==ty)
              {
                cout<<q[head][4]+1<<endl;
                return 0;
              }
              if (!vis[xx][yy][q[head][0]][q[head][1]])
              {
                tail++;
                if (tail>5000000) tail=1;
                q[tail][0]=xx; q[tail][1]=yy; q[tail][2]=q[head][0]; q[tail][3]=q[head][1]; q[tail][4]=q[head][4]+1;
                vis[xx][yy][q[head][0]][q[head][1]]=1;
              }
            }
            else
            {
              if (!vis[xx][yy][q[head][2]][q[head][3]])
              {
                tail++;
                if (tail>5000000) tail=1;
                q[tail][0]=xx; q[tail][1]=yy; q[tail][2]=q[head][2]; q[tail][3]=q[head][3]; q[tail][4]=q[head][4]+1;
                vis[xx][yy][q[head][2]][q[head][3]]=1;
              }
            }
          }
        }
      }
    }
    while (head!=tail);
    cout<<-1<<endl;
    return 0;
}

int work()
{
    for (int i=1;i<=qu;i++)
    {
      scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
      memset(vis,0,sizeof(vis));
      vis[ex][ey][sx][sy]=1;
      bfs();
    }
    return 0;
}

int main()
{
    file_open();
    init();
    work();
    //system("pause");
    file_close();
    return 0;
}
