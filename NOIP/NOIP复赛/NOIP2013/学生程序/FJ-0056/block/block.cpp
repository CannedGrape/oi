#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define N 100010
using namespace std;
int n,h[N];
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i,j,ans,maxh;
    bool flag;
    ans=maxh=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++) 
      {scanf("%d",&h[i]);
       maxh=max(maxh,h[i]);
      }
    if (n<=1000)  
       {j=1;
        while (j<=maxh)
          {flag=1;
           for (i=1;i<=n;i++) 
             {if (h[i]>=j && flag) {ans++; flag=0;}
              else if (h[i]<j) flag=1;
             }
           j++;
          }
       }
    else
       {ans=h[1];
        for (i=2;i<=n;i++) if (h[i]>h[i-1]) ans+=h[i]-h[i-1];
       }    
    printf("%d\n",ans);  
    fclose(stdin);
    fclose(stdout);
    return 0;
}
