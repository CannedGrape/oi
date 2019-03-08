#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
long long n,m;
void pd(long long r[],long long dsj[][3])
{long long i=1,j;
 while (i<=m)
     {j=dsj[i][1];
      while (j<=dsj[i][2])
         {r[j]-=dsj[i][0];
          if (r[j]<0)
             {printf("-1\n%lld\n",i);
              break;j-=2;
             }
          j++;
         }
      if (j<dsj[i][2])
         break;
      i++;
     }
 if (i==m)
    printf("0\n");
}
int main()
{freopen ("classroom.in","r",stdin);
 freopen ("classroom.out","w",stdout);
 scanf("%lld %lld",&n,&m);
 long long r[n+1],dsj[m][3];
 r[0]=0;dsj[0][0]=0;dsj[0][1]=0;dsj[0][2]=0;
 for (long long i=1;i<=n;i++)
     scanf("%lld",&r[i]);
 for (long long i=1;i<=m;i++)
     scanf("%lld %lld %lld",&dsj[i][0],&dsj[i][1],&dsj[i][2]);
 pd(r,dsj);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
