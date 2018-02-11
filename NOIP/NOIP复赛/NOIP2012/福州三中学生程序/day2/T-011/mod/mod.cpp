#include<iostream>
#include<stdin.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long long t,h,a,b,x,c,d,i;
    t=0;
    d=0;
    i=1;
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    cin>>a>>b;
    h=b%a;
    while(t==0)
    {
       d++;
       c=a*i%b;
       i++;
       if(c==h)
       t=1;}
    cout<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
