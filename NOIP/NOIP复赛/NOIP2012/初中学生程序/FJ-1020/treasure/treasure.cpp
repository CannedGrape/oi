#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
long long n,m,now;
bool a[10001][101];
long long b[10001][101];
int main ()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    cin>>n>>m;
    long long i,j,sum=0,k;
    for (i=1;i<=n;i++)
      for (j=0;j<=m-1;j++)
      {
         cin>>a[i][j];
         cin>>b[i][j];
      }
    cin>>now;
    for (i=1;i<=n;i++)
    {
       sum=sum+b[i][now];
       j=0;
       k=now;
       while (j<b[i][now])
       {
          if (a[i][k])
            j++;
          if (k==m-1)
            k=0;
          else
            k++;
       }
       now=k-1;
       if(now==-1)
         now=m-1;
    }
    cout<<sum%20123;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
