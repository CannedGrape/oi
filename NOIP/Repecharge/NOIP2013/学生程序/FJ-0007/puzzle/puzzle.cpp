#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=35;
const int INF=0x7fffffff;
int M[maxn][maxn];
bool a[maxn][maxn];
bool b[maxn][maxn];
int EX[500];//表示空白格子 
int EY[500];
int SX[500];//表示可移动的棋子的初始位置 
int SY[500];
int TX[500];//表示目标位置 
int TY[500];
int nowx,nowy;
int n1,m,q;
int k;
int ans=INF;
void bldfs(int x,int y,int n)
{
 //    cout<<x<<" "<<y<<endl;
     if(!b[x][y])b[x][y]=1;else return ;
   if(x<1 ||y<1)
   return ;
   if(nowx==TX[k] && nowy==TY[k])
      {ans=min(n,ans);return ;}
   if(a[x-1][y])
     {  if(x-1==nowx && y==nowy) 
          nowx=x,nowy=y;
     bldfs(x-1,y,n+1);
   }
   if(a[x][y-1])
       {  if(x==nowx && y-1==nowy) 
         nowx=x,nowy=y;
         bldfs(x,y-1,n+1);
       }
      if(a[x+1][y])
        { 
          if(x+1==nowx && y==nowy) 
         nowx=x,nowy=y;
         bldfs(x+1,y,n+1);
         }
       if(a[x][y+1])
       {  
         if(x==nowx && y+1==nowy) 
         nowx=x,nowy=y;
       bldfs(x,y+1,n+1);}
  return ;
   
}
void init()
{
   scanf("%d%d%d",&n1,&m,&q);
   for(int i=1;i<=n1;i++)
     for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
   for(int i=1;i<=q;i++)
     { k=i; ans=INF;
       scanf("%d%d%d%d%d%d",&EX[i],&EY[i],&SX[i],&SY[i],&TX[i],&TY[i]);nowx=SX[i],nowy=SY[i];
       bldfs(EX[i],EX[i],0);cout<<(ans==INF?-1:ans)<<"\n";
     memset(b,0,sizeof(b));  
     }
}
int main()
{
   freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
   // system("pause");
     fclose(stdin);
    fclose(stdout);       
    return 0;
}
