#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int i,j,k,q,n,m,x,y,z;
int path[10000][10000],s[50000],e[50000];

int min(int a,int b)
{
    if(a<=b)
      return a;
    else
      return b;
}

int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d %d",&n,&m);
    memset(path,-1,sizeof(path));
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(path[x][y]<z)
        {
           path[x][y]=z;
           path[y][x]=z;
        }
    } 
    scanf("%d",&q);
    for(i=1;i<=q;i++)
      scanf("%d %d",&s[i],&e[i]);
    for(i=1;i<=m;i++)
      for(j=1;j<=m;j++)
        for(k=1;k<=m;k++)
          if(i!=j&&i!=k&&k!=j&&min(path[i][k],path[k][j])>path[i][j])
          {
              path[i][j]=min(path[i][k],path[k][j]);
              path[j][i]=path[i][j];
          }
    for(i=1;i<=q;i++)
      for(j=1;j<=m;j++)
        if(min(path[s[i]][j],path[j][e[i]])>path[s[i]][e[i]]&&j!=s[i]&&j!=e[i])
          path[s[i]][e[i]]=min(path[s[i]][j],path[j][e[i]]);
    for(i=1;i<=q;i++)
      printf("%d\n",path[s[i]][e[i]]);      
    fclose(stdin);
    fclose(stdout);
    return 0;
}
