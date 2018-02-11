#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
#define MXN 1005
struct node
{
       int num,pos,ttt;
}s[MXN];
int n,m,h[MXN],tt,S;
double final=0;
int minn1=0x7fffffff,minn2=0x7fffffff,aa,ff,total=0;
node mynear1[MXN],mynear2[MXN];
void Init()
{
     scanf("%d",&n);
     for (int i=1;i<=n;i++) scanf("%d",&h[i]);
     scanf("%d%d",&tt,&m);
}
bool cmp(node x,node y)
{
     if(x.num!=y.num) return x.num<y.num;
     return x.pos<y.pos;
}
void find_answer1()
{
     int ass,bss,qq=0;
     final=0x7fffffff;
     for (int i=1;i<=n-1;i++)
       {
        for (int j=i+1;j<=n;j++){
            aa=abs(h[j]-h[i]);
            s[j-i].num=aa;s[j-i].pos=h[j];
            s[j-i].ttt=j;
            }
        sort(s+1,s+n-i+1,cmp);
        mynear1[i]=s[1];
        if(i<n-1) mynear2[i]=s[2];
        //printf("%d %d\n",s[1].ttt,s[2].ttt);
       }
     //start
     bool ok;
     for (int i=1;i<=n-1;i++)
       {total=0;
     ass=bss=0;
        int nowstart=i;
        ok=1;
        ff=0;
        while(ok)
          {ok=0;
            if(ff==0&&total+mynear2[nowstart].num<=tt&&mynear2[nowstart].ttt>nowstart)
              {
                ass+=mynear2[nowstart].num;
                total+=mynear2[nowstart].num;
                nowstart=mynear2[nowstart].ttt;
                ff=1;ok=1;
              }
            else if(ff==1&&total+mynear1[nowstart].num<=tt&&mynear1[nowstart].ttt>nowstart)
              {
               bss+=mynear1[nowstart].num;
               total+=mynear1[nowstart].num;
               nowstart=mynear1[nowstart].ttt;
               ff=0;
               ok=1;
              }
          }
        double w;
        if(bss!=0) w=double(ass)/double(bss);
        else w=0x7fffffff;
        if(w<final) {final=w;qq=i;}
        if(w==final&&h[i]>h[qq]){final=w;qq=i;}
       }
     printf("%d\n",qq);
}
void find_answer2()
{
     for (int i=1;i<=m;i++)
       {
         scanf("%d%d",&S,&tt);
         total=0;
         int nowstart=S,ass=0,bss=0;
         ff=0;
         bool ok=1;
         while(ok)
           {
             ok=0;
            if(ff==0&&total+mynear2[nowstart].num<=tt&&mynear2[nowstart].ttt>nowstart)
              {
                ass+=mynear2[nowstart].num;
                total+=mynear2[nowstart].num;
                nowstart=mynear2[nowstart].ttt;
                ff=1;ok=1;
              }
            else if(ff==1&&total+mynear1[nowstart].num<=tt&&mynear1[nowstart].ttt>nowstart)
              {
               bss+=mynear1[nowstart].num;
               total+=mynear1[nowstart].num;
               nowstart=mynear1[nowstart].ttt;
               ff=0;
               ok=1;
              }
           }
         printf("%d %d\n",ass,bss);
       }
}
void solve()
{
     find_answer1();
     find_answer2();
}
int main()
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    
    Init();
    solve();
    
    fclose(stdin);fclose(stdout);
    return 0;
}
