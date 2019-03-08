#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,q,ans;
int map[40][40],k[40][40];
int ex,ey,sx,sy,tx,ty;
bool gone[40][40],done;
int dx[8]={0,1,-1,0,0};
int dy[8]={0,0,0,1,-1};
void init()
{
     scanf("%d%d%d",&n,&m,&q);
     for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
         scanf("%d",&map[i][j]);
}
void addwall()
{
     for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       if(map[i][j])
       {
         if(map[i-1][j]+map[i+1][j]+map[i][j+1]+map[i][j-1]<2)
         map[i][j]=0;
       }
}
void road(int x,int y,int num)
{
     k[x][y]=num;
     for(int i=1;i<5;i++)
     if(map[x+dx[i]][y+dy[i]]&&!gone[x+dx[i]][y+dy[i]])
     {
       gone[x+dx[i]][y+dy[i]]=1;
       road(x+dx[i],y+dy[i],num+1);
     }
}
void getroad()
{
     if(map[tx][ty]==0||map[sx][sy]==0) {done=1; return;}
     int i,j;
     for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
       {
         gone[i][j]=0;
         k[i][j]=88888;
       }
     gone[sx][sy]=1;
     gone[ex][ey]=1;
     road(ex,ey,0);
     if(k[tx][ty]==88888) done=1;
}
int f[5010],x[5010],y[5010];
int get()
{
     int h=-1,t=0,xx,yy;
     x[0]=sx;
     y[0]=sy;
     bool go[35][35]={};
     go[sx][sy]=1;
     while(h<t)
     {
         h++;
         xx=x[h],yy=y[h];
         for(int i=1;i<5;i++)
         if(!go[xx+dx[i]][yy+dy[i]]&&map[xx+dx[i]][yy+dy[i]])
         {
             go[xx+dx[i]][yy+dy[i]]=1;
               t++;   f[t]=h;
             x[t]=xx+dx[i]; y[t]=yy+dy[i];
             if(x[t]==tx&&y[t]==ty) return t;
         }
     }
}
int xx[5010],yy[5010],num;
void makeroad(int o)
{
     num++;
     xx[num]=x[o];
     yy[num]=y[o];
     if(f[o]) makeroad(f[o]);
}
int ret(int cdx)
{
    int tx=xx[cdx],ty=yy[cdx];
    int h=-1,t=0,a,b;
    bool go[35][35]={};
    x[0]=ex; y[0]=ey; f[0]=0;
    go[ex][ey]=1;
    if(ex==tx&&ey==ty) return 0;
    while(h<t)
    {
        h++;
        a=x[h],b=y[h];
        for(int i=1;i<5;i++)
        if(!go[a+dx[i]][b+dy[i]]&&map[a+dx[i]][b+dy[i]])
        {
          t++; f[t]=f[h]+1;
          x[t]=a+dx[i]; y[t]=b+dy[i];
          if(x[t]==tx&&y[t]==ty) return f[t];
        }
    }
}
void work()
{
     ans=0; done=0;
     getroad();
     if (done) { done=0; return; }
     int last=get(),add;
     num=0;
     makeroad(last);
     xx[num+1]=sx;
     yy[num+1]=sy;
     for(int i=num;i;i--)
     {
         map[xx[i+1]][yy[i+1]]=0;
         add=ret(i);
         ans=ans+1+add;
         map[xx[i+1]][yy[i+1]]=1;
         ex=xx[i+1]; ey=yy[i+1];
     }
     done=1;
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    addwall();
    while(q--)
    {
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        work();
        if(!done) printf("-1\n");
          else cout<<ans<<endl;
    }
    return 0;
}

/*
3 4 2
0 1 1 1
0 1 1 0
0 1 0 0 
3 2 1 2 2 2
1 2 2 2 3 2
3 4 1
0 1 1 1
0 1 1 0
0 1 1 0 
3 2 1 3 3 3
*/
