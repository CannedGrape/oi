#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAH 1000000100
#define MAN 100010
#define MAM 10100
using namespace std;
int edge[MAN][2],d[2],h[MAN],s[MAM],lim[MAM];
void swap(int& a,int& b)
{
     int c=a; a=b; b=c;
}
int main()
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    int i,j,n,hh,num1,num2,dist1,dist2,x,m,ansnum;
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&h[i]);
    scanf("%d%d",&x,&m);
    for (i=1;i<=m;i++) scanf("%d%d",&s[i],&lim[i]);
    h[0]=MAH;
    for (i=1;i<=n;i++)
      {dist1=dist2=MAH;
       num1=num2=0;
       for (j=i+1;j<=n;j++)
        {hh=abs(h[i]-h[j]);
         if (hh<=dist2)
           {if (hh<dist2) 
              {dist2=hh;
               num2=j;
              }
            else if (h[num2]>h[j]) num2=j;
            if (dist1>=dist2)
              if (dist1>dist2)
                 {swap(dist1,dist2);
                  swap(num1,num2);
                 }
               else if (h[num1]>h[num2]) swap(num1,num2);  
           }  
        }
       edge[i][0]=num1;
       edge[i][1]=num2;
      }  
    double bz,ans;
    ans=MAH;
    ansnum=0;
    int tag,city,tot;
    for (i=1;i<=n;i++)
      {tag=1;
       d[0]=d[1]=0;
       tot=0; 
       city=i;
       while (edge[city][tag]!=0 && tot<x)
         {d[tag]+=abs(h[city]-h[edge[city][tag]]);
          if (tot+d[tag]>x)
            {d[tag]-=abs(h[city]-h[edge[city][tag]]);
             break;
            }
          else tot+=d[tag];  
          city=edge[city][tag];
          tag=tag^1;
         }
       if (d[0]==0) bz=MAH;
       else bz=1.0*d[1]/d[0];
       if (bz<ans) {ans=bz; ansnum=i;}
       else if (bz==ans && h[i]>h[ansnum]) ansnum=i;
      }
    printf("%d\n",ansnum);
    for (i=1;i<=m;i++)
      {tag=1;
       d[0]=d[1]=0;
       tot=0; 
       city=s[i];
       while (edge[city][tag]!=0 && tot<lim[s[i]])
         {d[tag]+=abs(h[city]-h[edge[city][tag]]);
          if (tot+d[tag]>lim[s[i]])
            {d[tag]-=abs(h[city]-h[edge[city][tag]]);
             break;
            }
          else tot+=d[tag];  
          city=edge[city][tag];
          tag=tag^1;
         }
       printf("%d %d\n",d[1],d[0]);  
      } 
    fclose(stdin);
    fclose(stdout);
    return 0;
}
