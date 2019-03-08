#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int n;
int a[1005],b[1005];
int s[1005];
bool can[1005];
long long ans,cj;
void work()
{
    int i;
    long long q=1;
    long long r=0;
    for(i=1;i<=n;i++)
    {
     q*=a[s[i-1]];
     if(q/b[s[i]]>r) r=q/(b[s[i]]);
    }
    ans=min(ans,r);
}

void dfs(int k)
{
    int i;
    for(i=1;i<=n;i++)
     if(!can[i])
     {
       can[i]=true;
       s[k]=i;
       if(k==n)
         work();
       else
         dfs(k+1);
       s[k]=0;
       can[i]=false;
     }
}
    
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int i;
    scanf("%d",&n);
    scanf("%d%d",&a[0],&b[0]);
    cj=a[0];
    for(i=1;i<=3;i++)
    {
      scanf("%d%d",&a[i],&b[i]);
      cj*=a[i];
    }
    if(n<=20)
    {
      ans=1000000000;
      for(i=1;i<=n;i++)
      {
        can[i]=0;
        s[i]=0;
      }
      dfs(1);
    }
    else
    {
      ans=1000000000;
      for(i=1;i<=n;i++)
      {
        ans=min(ans,(cj/a[i])/b[i]);
      }
    }
    printf("%I64d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
