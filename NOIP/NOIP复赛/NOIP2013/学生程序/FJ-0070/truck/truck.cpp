#include<iostream>
#include<stdio.h>
using namespace std;

int map[1050][1050]={0};
int mark[1050]={0};
int n,m,q;

int main ()
{
    freopen ("truck.in","r",stdin);
    freopen ("truck.out","w",stdout);
    cin>>n>>m;
    
    for (int i=1;i<=m;i++)
         {
          int x,y,temp;
          cin>>x>>y>>temp;
          if (mark[y]&&mark[x]) 
             {
              if (temp>mark[y]&&temp<mark[x]) {mark[y]=temp;map[x][y]=temp;}
              if (temp>mark[x]&&temp<mark[y]) {mark[x]=temp;map[y][x]=temp;}
             }
          else if (mark[x])
             {
              map[x][y]=temp;
              map[y][x]=temp;
              mark[y]=mark[x];
             }
          else if (mark[y])
             {
              map[x][y]=temp;
              map[y][x]=temp;
              mark[x]=mark[y];
             }
          else
             {
              mark[x]=temp;mark[y]=temp;
              map[x][y]=temp;
              map[y][x]=temp;
             }
         }
    cin>>q;
    while (q--)
          {
           int x,y;
           cin>>x>>y;
           if (map[x][y]) cout<<map[x][y]<<endl;
           else cout<<-1<<endl;
          }
    return 0;
}
