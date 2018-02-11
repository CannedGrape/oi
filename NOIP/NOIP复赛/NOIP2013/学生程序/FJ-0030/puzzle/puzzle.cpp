#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,q;
bool f[31][31];
int h[31]={0},s[31]={0};
int ans=0;
void sp(int &a,int &b)
{
     int t=a;a=b;b=t;
}
int pd(int x1,int y1,int x3,int y3)
{
    if(x1>x3)sp(x1,x3);
    if(y1>y3)sp(y1,y3);
    for(int i=x1;i<x3;i++)
      {
              if(s[i]!=s[i+1]){s[i]=s[i+1]=0;ans++;}
              else{return 1;}
              }
      for(int i=y1;i<y3;i++)
      {
              if(h[i]!=h[i+1]){h[i]=h[i+1]=0;ans++;}
              else{return 1;}
              }
      return 0;
}
void work()
{
      int x1,y1,x2,y2,x3,y3;
      cin>>x1>>y1>>x2>>y2>>x3>>y3;
      if((f[x3][y3]==0)||(f[x3+1][y3+1]+f[x3-1][y3+1]+f[x3+1][y3-1]+f[x3-1][y3-1]==0)){cout<<-1<<endl;return;}
      for(int i=1;i<=30;i++)
      h[i]=s[i]=1;
      h[y1]=s[x1]=0;
      if(pd(x1,y1,x3,y3)==0&&pd(x3,y3,x2,y2)==0)cout<<ans<<endl;
      else cout<<-1<<endl;
      return;
      }
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    cin>>n>>m>>q;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
          cin>>f[i][j];
      for(int k=1;k<=q;k++)
          {ans=0;work();}
    //system("pause");
    return 0;
}
