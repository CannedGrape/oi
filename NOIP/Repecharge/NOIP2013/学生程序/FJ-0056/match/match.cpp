#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
int n,m,total,a[15],f[1500][15],anslen,ans,len;
void change(int t,int s)
{
     if (t<n)
       {swap(a[t],a[t+1]);
        change(t+1,s+1);
        swap(a[t],a[t+1]);
        change(t+1,s);
       }
     else 
       {total++;
        f[total][0]=s;
        for (int i=1;i<=n;i++) f[total][i]=a[i];              
       }
}
void c2(int t,int s)
{
     if (t<n)
       {swap(a[t],a[t+1]);
        c2(t+1,s+1);
        swap(a[t],a[t+1]);
        c2(t+1,s);
       }
     else 
       {for (int j=1;j<=total;j++)
          {len=0;
           for (int i=1;i<=n;i++) len+=(a[i]-f[j][i])*(a[i]-f[j][i]); 
           if (len<anslen || anslen<0)
             {anslen=len;
              ans=f[j][0]+s;
             }
           else if (len==anslen && f[j][0]+s<ans) ans=f[j][0]+s;
          }
       }
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int i;
    anslen=ans=-1;
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    change(1,0);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    c2(1,0);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
