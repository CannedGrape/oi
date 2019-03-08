#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n,m;
bool b=true;
int maps[31][31];
int q;
bool ab[100001];
int part[1000001][4]; 
int maxx=210000000;
int p[1000001];
int whitex,whitey,kingx,kingy,castlex,castley;
int check(int x,int y,int x1,int y1)
{
    if(ab[x*2700+y*900+x1*30+y1]==0)
      return false;
    return true;  
}
void klp(int x,int y,int x1,int y1)
{
      ab[x*2700+y*900+x1*30+y1]=1;
}
void ss(int x,int y,int x1,int y1,int tot)
{
    int w,t,x2,y2,x3,y3;    
    w=0;t=1;
    part[1][0]=x;
    part[1][1]=y;  
    part[1][2]=x1;
    part[1][3]=y1;  
    p[1]=0;
    while(w<t)
    {
         w++;
         x2=part[w][0];
         y2=part[w][1];
         x3=part[w][2];
         y3=part[w][3];
         if(x2+1<=n&&maps[x2+1][y2]==1)
         {                                 
               if(x2+1==x3&&y2==y3)
               {x2++;x3--;}
               else
               {x2++;}
               if(check(x2,y2,x3,y3)==0)
               {
                   t++;
                   p[t]=p[w]+1;
                   part[t][0]=x2;
                   part[t][1]=y2;
                   part[t][2]=x3;
                   part[t][3]=y3;
                   klp(x2,y2,x3,y3);
                   //printf("%d %d %d %d   F\n",x2,y2,x3,y3);
                   if(x3==castlex&&y3==castley)
                   {printf("%d\n",p[t]);b=0;break;}                     
               }                                      
         }
         x2=part[w][0];
         y2=part[w][1];
         x3=part[w][2];
         y3=part[w][3];
         if(x2-1>=1&&maps[x2-1][y2]==1)
         {                    
               if(x2-1==x3&&y2==y3)
               {x2--;x3++;}
               else
               {x2--;}
               if(check(x2,y2,x3,y3)==0)
               {
                   t++;
                   p[t]=p[w]+1;
                   part[t][0]=x2;
                   part[t][1]=y2;
                   part[t][2]=x3;
                   part[t][3]=y3;
                   klp(x2,y2,x3,y3);
                   //printf("%d %d %d %d   S\n",x2,y2,x3,y3);
                   if(x3==castlex&&y3==castley)
                   {printf("%d\n",p[t]);b=0;break;}                     
               }                                      
         }
         x2=part[w][0];
         y2=part[w][1];
         x3=part[w][2];
         y3=part[w][3];
         if(y2+1<=n&&maps[x2][y2+1]==1)
         {                
               if(x2==x3&&y2+1==y3)
               {y2++;y3--;}
               else
               {y2++;}
               if(check(x2,y2,x3,y3)==0)
               {
                   t++;
                   p[t]=p[w]+1;
                   part[t][0]=x2;
                   part[t][1]=y2;
                   part[t][2]=x3;
                   part[t][3]=y3;
                   klp(x2,y2,x3,y3);
                   //printf("%d %d %d %d   T\n",x2,y2,x3,y3);
                   if(x3==castlex&&y3==castley)
                   {printf("%d\n",p[t]);b=0;break;}                     
               }                                      
         } 
         x2=part[w][0];
         y2=part[w][1];
         x3=part[w][2];
         y3=part[w][3];
         if(y2-1>=1&&maps[x2][y2-1]==1)
         {                      
               if(x2==x3&&y2-1==y3)
               {y2--;y3++;}
               else
               {y2--;}
               if(check(x2,y2,x3,y3)==0)
               {
                   t++;
                   p[t]=p[w]+1;
                   part[t][0]=x2;
                   part[t][1]=y2;
                   part[t][2]=x3;
                   part[t][3]=y3;
                   klp(x2,y2,x3,y3);
                   //printf("%d %d %d %d   Fourth\n",x2,y2,x3,y3);
                   if(x3==castlex&&y3==castley)
                   {printf("%d\n",p[t]);b=0;break;}                     
               }                                      
         }         
    }if(b==1)printf("-1\n");    
}
void init()
{
     scanf("%d%d%d",&n,&m,&q);
     for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d",&maps[i][j]);     
     for(int i=1;i<=q;i++)
     {b=1;for(int j=0;j<=90000;j++)ab[j]=0;scanf("%d%d%d%d%d%d",&whitex,&whitey,&kingx,&kingy,&castlex,&castley);
     maxx=210000000;ss(whitex,whitey,kingx,kingy,0);}
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    //system("pause");
    return 0;
}

        
