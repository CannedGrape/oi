#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
struct atype
{
       int ex;
       int ey;
       int sx;
       int sy;
       int press;
       int step;
}a[810300];
int head,tail;
bool flag[24300030];
int compress[4]={1,30,900,27000};
int mx[4]={0,0,1,-1};
int my[4]={1,-1,0,0};
int map[35][35];
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int n,m,q,i,j,aa,ex1,ey1,sx1,sy1,tx,ty,rx,ry;
    bool getf;
    scanf("%d%d%d",&n,&m,&q);
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        scanf("%d",&map[i][j]);
    for(aa=1;aa<=q;aa++)
      {memset(flag,0,sizeof(flag));
       getf=false;
       head=-1;tail=0;
       scanf("%d%d%d%d%d%d",&ex1,&ey1,&sx1,&sy1,&tx,&ty);
       ex1--;
       ey1--;
       sx1--;
       sy1--;
       tx--;
       ty--;
       if(tx==sx1&&ty==sy1)
         {cout<<0<<'\n';
          continue;
         }
       a[tail].ex=ex1;
       a[tail].ey=ey1;
       a[tail].sx=sx1;
       a[tail].sy=sy1;
       a[tail].press=ex1*compress[0]+ey1*compress[1]+sx1*compress[2]+sy1*compress[3];
       a[tail].step=0;
       flag[a[tail].press]=true;
       do
       {head++;
        for(i=0;i<4;i++)
          {rx=a[head].ex+mx[i];
           ry=a[head].ey+my[i];
           if(rx>=0&&rx<n&&ry>=0&&ry<m&&map[rx][ry])
              {tail++;
               a[tail].ex=rx;
               a[tail].ey=ry;
               a[tail].sx=a[head].sx;
               a[tail].sy=a[head].sy;
               a[tail].step=a[head].step+1;
               if(a[head].sx==rx&&a[head].sy==ry)
                 {a[tail].sx-=mx[i];
                  a[tail].sy-=my[i];
                 }
               if(a[tail].sx==tx&&a[tail].sy==ty)
                  {cout<<a[tail].step<<'\n';
                   getf=true;
                   break;
                  }
               a[tail].press=a[tail].ex*compress[0]+a[tail].ey*compress[1]+a[tail].sx*compress[2]+a[tail].sy*compress[3];
               if(flag[a[tail].press])
                  tail--;
               else
                  flag[a[tail].press]=true;
              }
           if(getf==true)
             break;
          }
          }
        while(head<tail&&getf==false);
        if(getf==false)
          cout<<-1<<'\n';
       }
      fclose(stdin);
      fclose(stdout);
      return 0;
}
          
