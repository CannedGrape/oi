#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#define MXN 1010
#define MXM 10010
using namespace std;
typedef long long ull;
double infdou;
int INF;
int n,m,h[MXN];
int next[MXN][2];
void init()
{
     infdou=1;
     for (int i=1;i<=15;i++)
       infdou*=10;
     INF=1;
     for (int i=1;i<=9;i++)
       INF*=10;
     INF*=2;INF++;
     //===================================================
     scanf("%d",&n);
     for (int i=1;i<=n;i++)
       scanf("%d",&h[i]);
     h[n+1]=-INF;
     for (int i=1;i<=n;i++)
     {
       int min1=INF,min2=INF,index1=0,index2=0;
       for (int j=i+1;j<=n;j++)
       {
         if (abs(h[j]-h[i])<min1||abs(h[j]-h[i])==min1&&h[j]<h[index1])
         {
           min2=min1;  index2=index1;
           min1=abs(h[j]-h[i]);  index1=j;
         }
         else if (abs(h[j]-h[i])<min2||abs(h[j]-h[i])==min2&&h[j]<h[index2])
         {
           min2=abs(h[j]-h[i]);index2=j;
         }
       }
       next[i][1]=index1;
       next[i][0]=index2;
     }
}
ull len[2];
void solve()
{
     int x,ind=n+1;
     double bl=infdou;
     scanf("%d",&x);
     for (int i=n;i>=1;i--)
     {
       int s=i;
       len[0]=len[1]=0;
       bool j=0;//0是小A开，1是小B开 
       while (next[s][j]!=0&&len[0]+len[1]+(ull)abs(h[s]-h[next[s][j]])<=x)
       {
         len[j]+=(ull)abs(h[s]-h[next[s][j]]);
         s=next[s][j];
         j=!j;
       }
       double t;
       if (len[1]!=0)  t=len[0]/double(len[1]);
       else  t=infdou;
       if (t<bl||t==bl&&h[i]>h[ind])  
       {
         bl=t;
         ind=i;//ind的high初始化！
       }
          
       //cout<<t<<endl;
     }
     printf("%d\n",ind);
     //==========================================================
     scanf("%d",&m);
     for (int i=1;i<=m;i++)
     {
       int s;
       scanf("%d%d",&s,&x);
       len[0]=len[1]=0;
       bool j=0;
       while (next[s][j]!=0&&len[0]+len[1]+(ull)abs(h[s]-h[next[s][j]])<=x)
       {
         len[j]+=(ull)abs(h[s]-h[next[s][j]]);
         s=next[s][j];
         j=!j;
       }
       printf("%lld %lld\n",len[0],len[1]);
     }
}
int main ()
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
