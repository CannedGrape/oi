#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
long long n,i,a=0,b=0,j;
bool aa,bb;
int main ()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
    {
       aa=0;
       bb=0;
       if (n%i==0)
       {
          a=i;
          b=n/i;
          j=2;
          while (a%j!=0&&j<=a)
            j++;
          if (j==a)
            aa=1;
          else
            aa=0;
          j=2;
          while (b%j!=0&&j<=b)
            j++;
          if (j==b)
            bb=1;
          else
            bb=0;
          if (aa&&bb)
            break;
       }
    }
    if (a>b)
      cout<<a;
    else
      cout<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
