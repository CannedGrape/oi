#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int f[2001][2001];
int Max(int a,int b) { return a>b?a:b; }
int Min(int a,int b) { return a<b?a:b; }

int main ()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int n,m,p,a,b,c;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; ++i)
      {
        scanf("%d%d%d",&a,&b,&c);
        f[a][b]=f[b][a]=c;
      }
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=n; ++j)
        for (int k=1; k<=n; ++k)
          f[i][j]=Max(f[i][j],Min(f[i][k],f[k][j]));
    scanf("%d",&p);
    for (int i=1; i<=p; ++i)
      {
         scanf("%d%d",&a,&b);
         if (f[a][b]==0) printf("-1\n");
         else 
           printf("%d\n",f[a][b]);
      }
    fclose(stdin); fclose(stdout);
}
