#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
long long n,maaxx;
bool a[200000001];
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    int i,j;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
      for(j=2;j<=i;j++)
        if(i%j==0&&i!=j)
          a[i]=true;
    if(!a[n])
      printf("%lld",n);
    else
      {for(i=2;i<=n;i++)
         {if(n%i==0&&n!=i&&!a[i])
            maaxx=i;}
       printf("%lld",maaxx);}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
