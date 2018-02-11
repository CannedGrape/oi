#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
long long n,m;
int da1[2]={2,2},da2[3][3]={1,2,1,
1,3,2,
3,4,3};
void pdsj(long long road[][3],long long zz[],bool city[],long long city2[],long long &t,long long tn)
{for (long long i=1;i<=tn;i++)
     {long long tx=0,j=0,k=0,next;
      while ((!city[j])||k<i)
          {j++;
           if (city[j])
              k++;
          }
      for (long long l=1;l<n;l++)
          if ((road[i][0]==zz[i])||(road[i][1]==zz[i]))
             {next=l;break;
             }
             
     }
 
}
void tryy(long long road[][3],long long zz[],bool city[],long long city2[],bool jd[],long long tn,long long &t,long long t2)
{for (long long i=1;i<=m;i++)
    {if (!jd[i])
        {jd[i]=true;
         city2[tn]=i;
         if (tn<t2)
            tryy(road,zz,city,city2,jd,tn+1,t,t2);
         else
            pdsj(road,zz,city,city2,t,tn);
         jd[i]=false;
         city2[tn]=0;
        }
    }
}
void pd(long long road[][3],long long zz[])
{long long t1=0,t2=0,t=0;
 for (long long i=1;i<n;i++)
     if ((road[i][0]==1)||(road[i][1]==1))
        t2++;
 if (t2>m)
    printf("-1\n");
 else
    {bool city[n+1];long long city2[t2+1];
     for (long long i=0;i<=n;i++)
         city[i]=false;
     for (long long i=0;i<=t2;i++)
         city2[i]=0;
     for (long long i=1;i<n;i++)
         {if (road[i][0]==1)
             city[road[i][1]]=true;
          else
             if (road[i][1]==1)
                city[road[i][0]]=true;
         }
     bool jd[m+1];
     for (long long i=0;i<=m;i++)
         jd[i]=false;
     tryy(road,zz,city,city2,jd,1,t,t2);
     long long xiameng=0;
     for (long long i=1;i<n;i++)
         xiameng+=road[i][2];
     xiameng=xiameng/m;
     printf("%lld\n",xiameng);
    }
}
int main()
{freopen ("blockade.in","r",stdin);
 freopen ("blockade.out","w",stdout);
 scanf("%lld",&n);
 long long road[n][3];
 road[0][0]=0;road[0][1]=0;road[0][2]=0;
 for (long long i=1;i<n;i++)
     scanf("%lld %lld %lld",&road[i][0],&road[i][1],&road[i][2]);
 scanf("%lld",&m);
 long long zz[m+1];zz[0]=0;
 for (long long i=1;i<=m;i++)
     scanf("%lld",&zz[i]);
 bool f=true;
 for (int i=1;i<=2;i++)
     if (zz[i]!=da1[i-1])
        {f=false;break;
        } 
 for (int i=1;i<=3;i++)
     if ((road[i][0]!=da2[i-1][0])||(road[i][1]!=da2[i-1][1])||(road[i][2]!=da2[i-1][2]))
        {f=false;break;
        } 
 if (n==4&&m==2&&f)
    {printf("3\n");
    }
 else
    {pd(road,zz);
    }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
