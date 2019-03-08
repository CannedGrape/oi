#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

  int n,m,k,x;
  long long t,l,p;

int main()
{
    int i;
    
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&k,&x);
    t=1;
    for (i=1;i<=k;i++)
    {
        t=t*10;
        t=t%n;
    }
    t=(t*m+x)%n;
    printf("%d",t);
    return 0;
}
