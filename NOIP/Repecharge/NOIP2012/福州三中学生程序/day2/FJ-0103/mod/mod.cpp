#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
long long i,a,b;
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    scanf("%lld%lld",&a,&b);
     i=1;
     while((a*i)%b!=1)
      i++;
     printf("%lld\n",i);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
