#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int n,m,i,k,j;
    cin>>n>>m;
    int a[m][n];
    memset(a,0,sizeof(a));
    for(i=0;i<m;i++)
   {
      cin>>k;
      for(j=0;j<k;j++)
     {
        cin>>a[i][j];
     }
   }
    cout<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
