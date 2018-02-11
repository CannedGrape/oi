#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int n,m,k,x;

long long powerTen(const int upper)
{
    if (upper==0)
        return 1LL;
    long long tmp=powerTen(upper>>1LL);
    if (upper%2)
        return (((tmp*tmp)%n)*10)%n;
    else
        return (tmp*tmp)%n;
}

long long increment;

int main()
{ 
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d%d%d%d", &n, &m, &k, &x);
    increment=powerTen(k) * (long long)m;
    increment=increment%(long long)n;
    int ans=(int) ((x+increment)%n);
    printf("%d\n",ans);  
    return 0;    
}
