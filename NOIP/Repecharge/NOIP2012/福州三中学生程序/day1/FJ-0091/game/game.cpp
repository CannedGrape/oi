#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
#define MXN 1010
struct node
{
       long long leftt,rightt;
}a[MXN];
int n;
long long total,minn,final;
int minx;
bool flag[MXN];
void Init()
{
     scanf("%d",&n);
     total=1;
     for (int i=0;i<=n;i++)
       {
         scanf("%lld%lld",&a[i].leftt,&a[i].rightt);
         total*=a[i].leftt;
       }
}
void solve()
{
     long long aa,aaa;
     for (int tt=1;tt<=n;tt++)
      {
       minn=0x7fffffff;
       for (int i=1;i<=n;i++)
        if(!flag[i])
        {
         aa=(total/a[i].leftt)/a[i].rightt;
         if(minn>aa)
           {
            minn=aa;
            minx=i;
           }
        }
       total/=a[minx].leftt;
       aaa=minn;
       if(aaa>final)final=aaa;
       flag[minx]=1;
      }
     printf("%lld\n",final);
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    
    Init();
    solve();
    
    fclose(stdin);fclose(stdout);
    return 0;
}
