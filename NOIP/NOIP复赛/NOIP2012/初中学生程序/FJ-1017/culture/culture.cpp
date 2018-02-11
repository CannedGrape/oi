#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
const int oo=100000000;
int n,m,k,c[101],dis[101][101],s,t;
bool b[101][101],v[101];
void doing(int x)
{
     int i,j,k,posi,posj;
     v[x]=1;
     for(i=1;i<=n;i++){
       for(j=1;j<=n;j++)
         if(v[j]==0&&v[i]==0&&b[c[x]][c[j]]==0&&b[c[j]][c[i]]==0&&dis[x][j]+dis[j][i]<dis[x][i]){
           dis[x][i]=dis[x][j]+dis[j][i];posj=j;}
       v[posj]=1;
       v[i]=1;
       posi=0;posj=0;
       }
}
int main()
{
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    int i,j,x,y,z;
    scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
    for(i=1;i<=k;i++){
      scanf("%d",&x);
      c[i]=x;
      }
    for(i=1;i<=k;i++)
      for(j=1;j<=k;j++){
        scanf("%d",&x);
        if(x==0)
          b[i][j]=0;
        else
          b[i][j]=1;
        }
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        dis[i][j]=oo;
    for(i=1;i<=m;i++){
      scanf("%d%d%d",&x,&y,&z);
      dis[x][y]=z;dis[y][x]=z;
      if(b[c[x]][c[y]]==1&&b[c[y]][c[x]]==1)
        dis[x][y]=dis[y][x]=-oo;
      }
    doing(s);
    cout<<max(dis[s][t],-1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
