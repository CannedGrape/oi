#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAN 1010
using namespace std;
long long ans,tt,tot,q;
int n,a[MAN],b[MAN],k[MAN];
bool pd[MAN];
void work(int t,long long q)
{
     for (int i=1;i<=n;i++)
       {if (!pd[i])
          {tt=q/b[i];
           if (tt>=ans) return;
           pd[i]=1;
           if (t==n) ans=tt;
           else work(t+1,q*a[i]);
           pd[i]=0;
          }
       }
}
bool check(int x)
{
     q=tot;
     int limit,num;
     for (int j=1;j<=n;j++)
       for (int i=1;i<=n;i++)
         {limit=num=0;
          if (q/a[i]/b[i]>=limit && q/a[i]/b[i]<=x) 
            {limit=q/a[i]/b[i];
             num=i;
            }
          if (num==0) return 0;
          q/=a[num];  
         }
     return 1;  
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int i;
    scanf("%d",&n);
    for (i=0;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    ans=0x7fffffff;
    if (n<=15) 
      {work(1,a[0]);
       printf("%lld\n",ans);
      }
    else
      {tot=a[0];
       for (i=1;i<=n;i++) tot*=a[i];
       long long l,r,mid;    
       l=0; r=tot; ans=tot;
       while (l<=r)
         {mid=(l+r)>>1;
          if (check(mid)) {ans=mid; r=mid-1;}
          else l=mid+1;
         }
       printf("%lld\n",ans);
      }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
