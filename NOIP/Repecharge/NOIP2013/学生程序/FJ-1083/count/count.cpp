#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,x,ans;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
      {
      if(i%10==x)ans++;
      if(i/10%10==x && i>=10)ans++;
      if(i/100%10==x && i>=100)ans++;
      if(i/1000%10==x && i>=1000)ans++;
      if(i/10000%10==x && i>=10000)ans++;
      if(i/100000%10==x && i>=100000)ans++;
      if(i/1000000%10==x && i>=1000000)ans++;
      }
    printf("%d\n",ans);
    return 0;
}
