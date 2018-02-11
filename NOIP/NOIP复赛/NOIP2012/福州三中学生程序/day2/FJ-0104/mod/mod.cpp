#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
long long a,b,x=0;
void pd()
{long long ans=1;
 while (ans%a!=0)
    ans+=b;
 x=ans/a;
 printf("%lld\n",x);
}
int main()
{freopen ("mod.in","r",stdin);
 freopen ("mod.out","w",stdout);
 scanf("%lld %lld",&a,&b);
 pd();
 fclose(stdin);
 fclose(stdout);
 return 0;
}
