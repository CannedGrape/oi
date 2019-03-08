#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
struct Q
{
       int x,y;
};
Q s[5];
int n,m,q;
int ex,ey,sx,sy,tx,ty;
int map[32][32];
bool mark[32][32];
int t,ans;
void doing(int x,int y)
{
     if(clock()>800){cout<<t;exit(0);}
     if(x>n||x<1||y>m||y<1)
     return;
     if(map[x][y]==0)
     return;
     if(mark[x][y]==true)
     return;
     if(map[tx][ty]==2)
     {
                       ans=min(t,ans);
                       //cout<<ans<< " ";
                       return;
     }
     for(int i=1;i<=4;i++)
     {
             t++;
             int x1=x+s[i].x;
             int y1=y+s[i].y;
             int temp=map[x][y];
             if(map[x1][y1]!=0)
             {
             /*for(int i=1;i<=n;i++){
                     for(int j=1;j<=m;j++)
                     cout<<map[i][j]<<" ";
                     cout<<endl;}
                     cout<<endl;*/
             map[x][y]=map[x1][y1];
             map[x1][y1]=temp;
             mark[x][y]=true;
             doing(x1,y1);
             mark[x][y]=false;
             map[x1][y1]=map[x][y];
             map[x][y]=temp;
             }
             t--;
     }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    s[1].x=1;s[1].y=0;
    s[2].x=0;s[2].y=1;
    s[3].x=-1;s[3].y=0;
    s[4].x=0;s[4].y=-1;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    scanf("%d",&map[i][j]);
    
    for(int i=1;i<=q;i++)
    {
            t=0;
            ans=999;
            scanf("%d %d %d %d %d %d",&ex,&ey,&sx,&sy,&tx,&ty);
            map[sx][sy]=2;
            map[ex][ey]=3;
            doing(ex,ey);
            if(ans!=999)
            cout<<ans<<endl;
            else
            cout<<-1<<endl;
            map[sx][sy]=1;
            map[ex][ey]=1;
            
    }
    //cout<<clock();
    //system("pause");
}
