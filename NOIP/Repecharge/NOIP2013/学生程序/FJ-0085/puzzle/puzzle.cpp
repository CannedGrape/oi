#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int n,m,q;
int ex,ey,sx,sy,tx,ty;
int tail,end,last,ans;
int map0[40][40];
bool hash[31][31][31][31],pass;
int st[820000][4];
int l[5]={0,0,0,1,-1},r[5]={0,1,-1,0,0};

void init()
{
     scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
     map0[ex][ey]=2,map0[sx][sy]=3;
     st[1][0]=ex,st[1][1]=ey,st[1][2]=sx,st[1][3]=sy;
     hash[ex][ey][sx][sy]=true; //01¿Õ°×£¬23Æå×Ó 
}

void bfs()
{
     int xe,ye,xs,ys,x,y,xx,yy;
     tail=1,end=1,ans=0,pass=true; 
     
     while(pass && tail<=end)
     {last=0;
      
      for(int i=tail;i<=end;i++)
      {xe=st[i][0],ye=st[i][1],xs=st[i][2],ys=st[i][3];
       if(xs==tx && ys==ty) {pass=false;break;}
       
       for(int j=1;j<=4;j++) 
       {x=xe+l[j],y=ye+r[j],xx=xs,yy=ys;
        if(x==xx && y==yy) xx=xe,yy=ye;
        if(map0[x][y]!=0 && hash[x][y][xx][yy]==false)
        {last++;
         hash[x][y][xx][yy]=true;
         st[end+last][0]=x;
         st[end+last][1]=y;
         st[end+last][2]=xx;
         st[end+last][3]=yy;
        }
       }
      }
      
      tail=end+1,end+=last;
      if(pass) ans++;
      //  for(int i=tail;i<=end;i++)
    //     cout<<st[i][0]<<" "<<st[i][1]<<" "<<st[i][2]<<" "<<st[i][3]<<endl;
     
     }
    // system("pause");
     for(int i=1;i<=end;i++)
       hash[ st[i][0] ][ st[i][1] ][ st[i][2] ][ st[i][3] ]=false;
}

void print()
{
     if(pass) ans=-1;
     cout<<ans<<endl;
}

int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
     scanf("%d",&map0[i][j]);
    for(int i=1;i<=n;i++)
      map0[i][0]=0,map0[i][m+1]=0;
    for(int i=1;i<=m;i++) 
      map0[0][i]=0,map0[n+1][i]=0;
    
    while(q>0){
    init();
    bfs();
    print();
    q--;}
    
    fclose(stdin);
    fclose(stdout);
  //  system("pause");
    return 0;
}
