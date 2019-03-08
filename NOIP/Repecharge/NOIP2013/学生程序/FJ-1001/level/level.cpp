#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m,tkb[2000][2000],level[2000],zld,maxlevel=0;
bool tk__(int u,int v)
{
     int q;
     for(q=1;q<=tkb[u][0];q++)
       if(tkb[u][q]==v) return true;
     return false;
}
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int i,j,k;
    cin>>n>>m;
    for(i=1;i<=m;i++)
      {
       cin>>tkb[i][0];
       for(j=1;j<=tkb[i][0];j++)
         cin>>tkb[i][j];
      }
    for(i=1;i<=n;i++)
      level[i]=1;
    for(i=1;i<=m;i++)
      {
       zld=level[tkb[i][1]];
       for(j=2;j<=tkb[i][0];j++)
         if(level[tkb[i][j]]<zld) zld=level[tkb[i][j]];
       for(j=tkb[i][1];j<=tkb[i][tkb[i][0]];j++)
         {
          if(level[j]>=zld&&tk__(i,j)==false) 
            {for(k=1;k<=tkb[i][0];k++)
               if(level[tkb[i][k]]<=level[j]) level[tkb[i][k]]=level[j]+1;
            }
         }
      }
    for(i=1;i<=n;i++)
      if(level[i]>maxlevel) maxlevel=level[i];
    cout<<maxlevel<<endl;
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
