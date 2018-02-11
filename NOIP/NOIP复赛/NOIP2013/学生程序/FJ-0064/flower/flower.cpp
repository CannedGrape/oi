#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
long long n,h[100001]={};
long long ans1=1,ans2=1;

int main()
{freopen("flower.in","r",stdin);
 freopen("flower.out","w",stdout);
 scanf("%lld",&n);
 for (long long i=1;i<=n;i++)
    {scanf("%lld",&h[i]);
     if (i>=3)
        {if (h[i-2]>h[i-1]&&h[i]>h[i-1])
            {ans1+=2;
            }
         if (h[i-2]<h[i-1]&&h[i]<h[i-1])
            {ans2+=2;
            }
        }
    }
 if (ans1>ans2)
    {printf("%lld\n",ans1);
    }
 else
    {printf("%lld\n",ans2);
    }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
