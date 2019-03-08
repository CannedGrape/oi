#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int i,n,m,k,x;

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&k,&x);
    for(i=1;i<=k;i++)
      x=(x+10*m)%n;
    printf("%d\n",x);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
