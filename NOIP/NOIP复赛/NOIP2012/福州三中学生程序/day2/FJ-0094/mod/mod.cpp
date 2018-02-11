#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    long long i,a,b,m;
    scanf("%lld%lld",&a,&b);
    i=b;
    while(1)
    {
      m=(i+1)%a;
      if(m==0)
      {
        printf("%lld\n",(i+1)/a);
        break;
      }
      i=i+b;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
