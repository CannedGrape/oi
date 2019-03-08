#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int ta,tb,ans;
long long a,b,ca,cb;
void exgcd(long long x,long long y,long long &a,long long &b)
{
    if((x==1)&&(y==0))
    {
        a=1; b=0; return;
    }
    long long la=0,lb=0;
    exgcd(y,x%y,la,lb);
    a=lb;
    b=la-lb*(x/y);
    return;
}
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    scanf("%d%d",&ta,&tb);
    a=ta; b=tb; 
    if(a>b)
    {
        exgcd(a,b,ca,cb);
        ca=(ca+a*b)%b;
        ans=ca;
        printf("%d\n",ans);
    }
    else
    {
        exgcd(b,a,cb,ca);
        ca=(ca+a*b)%b;
        ans=ca;
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
