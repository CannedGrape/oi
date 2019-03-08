#include<iostream>
using namespace std;
#include<cstdio>
struct data{int x,y,z;};
struct che{ int x,y;};
struct shuju{ int z,pd;};
int main()
{
    freopen("truck.in","r",stdin);
freopen("truck.out","w",stdout);
    int n,m,i,q,j,l;
     cin>>n>>m;
 data a[m+1];
 
  shuju c[m+1][m+1];
for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
 {c[i][j].z=99999;
 c[i][j].pd=0;}
 
for(i=1;i<=m;i++)
 {cin>>a[i].x>>a[i].y>>a[i].z;
 c[a[i].x][a[i].y].pd=1;
 c[a[i].x][a[i].y].z=a[i].z;}
 cin>>q;
 che b[q+1];
 for(i=1;i<=q;i++)
 cin>>b[i].x>>b[i].y;
 
 for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   {if(c[i][j].pd) for(l=1;l<=n;l++)
   if(c[j][l].pd) {c[i][l].pd=1;
   c[i][l].z=min(c[i][j].z,c[j][l].z);}}
for(i=1;i<=q;i++)
{if(c[b[i].x][b[i].y].pd==0)cout<<-1<<endl;
else cout<<c[b[i].x][b[i].y].z<<endl;}
 return 0;
}
