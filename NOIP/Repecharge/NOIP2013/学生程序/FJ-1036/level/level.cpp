#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

long long a[1000001];

int main ()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int n,m,k=0,a1,Ans=0;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; ++i)
      {
         scanf("%d",&k);
         for (int i=1; i<=k; ++i)
           scanf("%d",&a1),++a[a1];
      }
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=n; ++j)
        if (i!=j && a[i]==a[j]) a[j]=0;
    for (int i=1; i<=n; ++i)
      if (a[i]!=0) ++Ans;
    printf("%d",Ans);
    fclose(stdin);
    fclose(stdout);
}
