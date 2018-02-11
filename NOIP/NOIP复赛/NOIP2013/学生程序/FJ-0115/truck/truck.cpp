#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
using namespace std;
int n,m,q;
int a[10001][10001]={};
bool b[10001][10001]={};
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,j,x,y,z,t;
    for (i=1;i<=10001;i++)
      a[i][i]=-1;
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if (z>a[x][y])
          a[x][y]=a[y][x]=z;
        b[x][y]=b[y][x]=true;
    }
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
          if (b[i][j]==true)
          {
            for (x=1;x<=n;x++)
              if (b[j][x]==true)
                {
                  b[i][x]=b[x][i]=true;
                  if (a[j][x]>=a[i][j])
                    t=a[i][j];
                  else
                    t=a[j][x];
                  if (t>a[i][x])
                    a[i][x]=a[x][i]=t;
                }
          }
      }
    scanf("%d",&q);
    for (i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        if (b[x][y]==true)
          cout<<a[x][y]<<endl;
        else
          cout<<"-1"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
