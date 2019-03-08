#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,a[1001][1001]={};
inline int qx(int a,int b)
{if (a>b)return b;else return a;}
int main()
{   freopen("truck.in","r",stdin);freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    int i,j,x,y,l,q,k,z;
    bool sign=1,sign2=1;;
    for(i=1;i<=m;i++)
       {scanf("%d%d%d",&x,&y,&l);
        if(l>a[x][y]){a[x][y]=l;a[y][x]=l;}
       }
    for(i=1;i<=n;i++)a[i][i]=-1;
    while(sign) 
    {sign=0;
     for(i=1;i<=n;i++)
      for(j=i+1;j<=n;j++)
        if(a[i][j]!=-1)
          {sign2=1;
           for(k=1;k<=n;k++)
             {z=qx(a[i][k],a[j][k]);
                if(z>a[i][j])
                   {sign2=0;sign=1;
                    a[i][j]=z;
                    a[j][i]=z;
                   }
             }
           if(sign2&&a[i][j]==0){a[i][j]=-1;a[j][i]=-1;}
          }
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
      {scanf("%d%d",&x,&y);
       printf("%d\n",a[x][y]);
      }
    fclose(stdin);fclose(stdout);
    return 0;
}
