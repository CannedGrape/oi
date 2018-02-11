#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
long long x,y;
long long gcd(long long  a,long long b)
{
     if (a%b==0)  
     {
       x=0;y=1;
       return b;
     }
     long long t=gcd(b,a%b),tx=x;
     x=y;
     y=-a/b*y+tx;
     return t;
}
int main ()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    gcd(a,b);
    while (x-b>0)  x-=b;
    while (x<=0)  x+=b;
    cout<<x<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}
