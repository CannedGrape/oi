#include<iostream>
#include<stdio.h>
using namespace std;
int f[1010][1010],n,m;
void init()
{
     scanf("%d%d",&n,&m);
     int x,y,z;
     while(m--)
     {
         scanf("%d%d%d",&x,&y,&z);
         if(f[x][y]<z)
         {
             f[x][y]=z;
             f[y][x]=z;
         }
     }
}
void floyed()
{
     int i,j,k;
     for(k=1;k<=n;k++)
       for(i=1;i<=n;i++)
       if(i!=k)
         for(j=1;j<=n;j++)
         if(f[i][j]<min(f[i][k],f[k][j])) f[i][j]=min(f[i][k],f[k][j]);
}
void ans()
{
     int q,a,b,rat;
     scanf("%d",&q);
     while(q--)
     {
         scanf("%d%d",&a,&b);
         rat=f[a][b];
         if(rat) printf("%d\n",rat);
         else printf("-1\n");
     }
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    
    init();
    floyed();
    ans();
    return 0;
}

/*
4 3
1 2 4
2 3 3
3 1 1
3
1 3
1 4
1 3
*/
