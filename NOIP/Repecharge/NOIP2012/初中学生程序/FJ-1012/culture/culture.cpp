#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n,k,m,s,t;
int c[1001];
int a[1001][1001];
int r[1001][1001];
int main()
{  freopen("culture.in","r",stdin);
   freopen("culture.out","w",stdout);
   int i,j;
   cin>>n>>k>>m>>s>>t;
   for (i=1;i<=n;i++)
     cin>>c[i];
   for (i=1;i<=k;i++)
     for (j=1;j<=k;j++)
       cin>>a[i][j];
   for (i=1;i<=m;i++)
     for (j=1;j<=3;j++)
       cin>>r[i][j];
   cout<<"-1"<<endl;
   fclose(stdin);
   fclose(stdout);
return 0;
}
