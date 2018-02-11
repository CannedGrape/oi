#include<stdio.h>
#include<stdlib.h>
int n,m,k,x;
long long ans;
long long power(int x,int y)
{
    long long aa,base;
    aa=1,base=x;
    while(y!=0)
    {
        if(y&1) aa=(aa*base)%n;
        base=(base*base)%n;
        y/=2;
    }
    return aa%n;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int i;
    scanf("%d%d%d%d",&n,&m,&k,&x);
    ans=power(10,k)*(n-m)+x;
    printf("%lld\n",ans%n);
    return 0;
}
