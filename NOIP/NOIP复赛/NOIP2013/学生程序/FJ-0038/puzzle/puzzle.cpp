#include<iostream>
#include<cstdio>
using namespace std;
int a[40][40]={},n,m,Q,ex,ey,sx,sy,tx,ty,d[40][40][40][40]={};
bool b[40][40][40][40]={};
struct node
{
    int x1,y1,x2,y2;
}q[2000]={};
void init()
{
     scanf("%d%d%d",&n,&m,&Q);
     for(int i=1;i<=n;++i)
         for(int j=1;j<=m;++j)
             scanf("%d",&a[i][j]);
}
void clear()
{
     for(int i=1;i<=n;++i)
         for(int j=1;j<=m;++j)
             for(int ii=1;ii<=n;++ii)
                 for(int jj=1;jj<=m;++jj)
                     b[i][j][ii][jj]=false,d[i][j][ii][jj]=0x3fffffff;
}
inline void add_node(int &t,int x1,int y1,int x2,int y2,int dis)
{
     ++t;
     q[t].x1=x1;
     q[t].x2=x2;
     q[t].y1=y1;
     q[t].y2=y2;
     b[x1][y1][x2][y2]=true;
     d[x1][y1][x2][y2]=dis+1;
}
//指定棋子坐标(x1,y1) 空白格子坐标(x2,y2) 
void bfs()
{
     const int x_[5]={0,0,1,0,-1},y_[5]={0,1,0,-1,0};
     int head=0,tail=0;
     add_node(tail,sx,sy,ex,ey,-1);
     while(head<tail)
     {
         const node s=q[++head];
         //cout<<s.x1<<' '<<s.y1<<' '<<s.x2<<' '<<s.y2<<' '<<d[s.x1][s.y1][s.x2][s.y2]<<endl;
         for(int i=1;i<=4;++i)
         {
             int x2=s.x2+x_[i],y2=s.y2+y_[i];
             int x1,y1,dis=d[s.x1][s.y1][s.x2][s.y2];
             if(x2==s.x1 && y2==s.y1)
                 x1=s.x2,y1=s.y2;
             else
                 x1=s.x1,y1=s.y1;
             if(a[x2][y2]==0 || a[x1][y1]==0 || b[x1][y1][x2][y2])
                 continue;
             add_node(tail,x1,y1,x2,y2,dis);
             if(x1==tx && y1==ty)
             {
                 printf("%d\n",dis+1);
                 return;
             }
         }
     }
     printf("-1\n");
}
void work()
{
    for(int i=1;i<=Q;++i)
    {
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        clear(); 
        if(sx==tx && sy==ty)
            printf("0\n");
        else
            if(a[sx][sy]==0 || a[tx][ty]==0)
                printf("-1\n");
            else
                bfs();
    }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    work();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
