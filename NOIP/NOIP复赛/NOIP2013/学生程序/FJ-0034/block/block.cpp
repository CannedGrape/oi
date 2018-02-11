#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
int h[100010],n;
int main()
{
    int i,ans,height;
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&h[i]);
    ans=0;
    height=h[1];
    for(i=2;i<=n+1;i++)
      {if(h[i]>=height)
         height=h[i];
       else
         {ans+=(height-h[i]);
          height=h[i];
         }
      }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
      
