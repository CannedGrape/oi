#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int i,n,a[100001],b[100001];
long long ans=0;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
      scanf("%d",&b[i]);
    for(i=1;i<=n-1;i++)
      if(a[i]!=b[i])
        if(a[i+1]==b[i]&&a[i]==b[i+1])
        {
          swap(a[i],a[i+1]);
          swap(b[i],b[i+1]);
          ans++;
        }
    ans=ans%99999997;
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
