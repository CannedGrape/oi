#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
long long n;int h[100001]={};long long ans=0;;

int main()
{freopen("block.in","r",stdin);
 freopen("block.out","w",stdout);
 scanf("%lld",&n);
 long long xxxxx=1;
 for (long long i=1;i<=n;i++)
    {scanf("%d",&h[xxxxx]);
     if (h[xxxxx]==h[xxxxx-1])
        {xxxxx--;
        }
     if (h[xxxxx-2]<h[xxxxx-1]&&h[xxxxx-1]<h[xxxxx])
        {h[xxxxx-1]=h[xxxxx];xxxxx--;
        }
     if (h[xxxxx-2]>h[xxxxx-1]&&h[xxxxx-1]>h[xxxxx])
        {h[xxxxx-1]=h[xxxxx];xxxxx--;
        }
     if (i==n&&h[xxxxx]<=h[xxxxx-1])
        {xxxxx--;
        }
     xxxxx++;
    }
 xxxxx--;
 for (long long i=1;i<=xxxxx;i++)
    {if (h[i]>h[i+1])
        {ans+=h[i];
        }
     else
        {ans-=h[i];
        }
    }
 printf("%lld\n",ans);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
