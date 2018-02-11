#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
long long n,m,k,x,ans,md=0;
void modd1(long long a)
{while (a>=0)
    {a=a-n;
    }
 if (a<0)
    {md=a+n;
    }
 else
    {md=a;
    }
}
void modd2(long long a1)
{long long a=1;
 while (a1>=0)
     {a=a%n;a=a*10;a1--;
     }
 long long b=0;
 for (long long i=1;i<=a;i++)
     {b+=m;
     }
 while (b>=0)
    {b=b-n;
    }
 if (b>=0)
    {md=b;
    }
 else
    {md=b+n;
    }
}
int main()
{freopen("circle.in","r",stdin);
 freopen("circle.out","w",stdout);
 scanf("%lld %lld %lld %lld",&n,&m,&k,&x);
 modd1(x);ans=md;
 modd2(k);ans=ans+md;
 printf("%lld\n",ans);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
