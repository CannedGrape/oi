#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
int n,a,b;
long long itsmax;
void pd(int dc[][3])
{int max1=dc[0][1]/dc[1][2];
 for (int i=2;i<=n;i++)
     {int re=1;
      for (int j=0;j<i;j++)
          re=re*dc[j][1];
      re=re/dc[i][2];
      if (re>max1)
         max1=re;
     }
 if (itsmax>max1)
    itsmax=max1;
}
void tryy(bool p[],int t,int dc[][3])
{int i;
 for (i=1;i<=n;i++)
     {if (!p[i])
         {p[i]=true;
          if (t<n)
             tryy(p,t+1,dc);
          else
             pd(dc);
          p[i]=false;
         }
     }
}
int main()
{freopen ("game.in","r",stdin);
 freopen ("game.out","w",stdout);
 scanf("%d %d %d",&n,&a,&b);
 int dc[n+1][3];
 dc[0][0]=0;dc[0][1]=a;dc[0][2]=b;
 int i;
 for (i=1;i<=n;i++)
     {scanf("%d %d",&dc[i][1],&dc[i][2]);
      dc[i][0]=0;
     }
 itsmax=1;
 for (int i=1;i<=n;i++)
     itsmax=itsmax*dc[i][1];
 bool p[n+1];
 for (int i=0;i<=n;i++)
     p[i]=false;
 tryy(p,1,dc);
 printf("%lld\n",itsmax);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
