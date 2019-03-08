//circle 30%
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,k,m,x,tmp=1;
void init()
{
     scanf("%d%d%d%d",&n,&m,&k,&x);
     return;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    init();
    for(int i=0;i<k;i++)
      tmp=tmp*10;
    for(int i=0;i<tmp;i++)
      x=(x+m)%n;
    printf("%d",x);
    return 0;
}
