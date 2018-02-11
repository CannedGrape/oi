#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int i,n,m,k,x,ans,d[1000001];
long long a=1,b=0;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    for(i=0;i<=n;i++)
      d[i]=0;
    for(i=1;i<=k;i++)
    {
      a=a*10;
      a=a%n;
    }
    for(i=1;i<=n-1;i++)
    {
      b=b+n-m;
      b=b%n;
      d[i]=b;
    }
    if(x>=d[a])
      ans=x-d[a];
    else
      ans=x-d[a]+n;
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
