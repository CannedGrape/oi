#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,h[100002],f[100002][3];
int Max(int a,int b) { return a>b?a:b; }
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) scanf("%d",&h[i]);
    f[1][1]=f[1][2]=1;
    for (int j=n; j>=1; --j)
      for (int i=j; i<=n; ++i)
      {
          if (h[i-1]<h[i]) f[i][1]=Max(f[i-1][2]+1,f[i][1]);
          if (h[i-1]>h[i]) f[i][2]=Max(f[i-1][1]+1,f[i][2]);
          f[i][1]=Max(f[i][1],f[i-1][1]);
          f[i][2]=Max(f[i][2],f[i-1][2]);
      }
   // printf("%d %d\n",f[n-1][2],f[n][2]);
    printf("%d",Max(f[n][1],f[n][2]));
   // for (int i=1; i<=n; ++i) printf("%d ",f[i][1]);
    fclose(stdin); fclose(stdout);
}
