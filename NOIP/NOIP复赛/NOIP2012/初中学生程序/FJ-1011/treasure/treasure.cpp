#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n,m,s,toto,k=0,g;
int map[10001][101][2];
int maps[10001][101];
void tryy(int i,int j)
{
     toto=toto+map[i][j][1];
     g=j;
     if(i==n)
       {if(toto>=20123)
          toto=toto%20123;
        printf("%d",toto);
        return;}
     else 
       {while(k!=map[i][j][1])
         {cout<<i<<" "<<k<<" "<<g<<endl;if(g==m-1)
            {if(map[i][0][0]==1)
               k++;
             if(k!=map[i][j][1])
               g=0;}
          else
            {if(map[i][g][0]==1)
               k++; 
             g++;}
          
          }
       k=0;
       tryy(i+1,g);}
}
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n-1;i++)
      for(int j=0;j<=m-1;j++)
        scanf("%d%d",&map[i][j][0],&map[i][j][1]);
    scanf("%d",&s);
    tryy(0,s);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
