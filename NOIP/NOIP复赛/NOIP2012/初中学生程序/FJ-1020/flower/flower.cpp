#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int n,m,rest;
int a[101],b[101];
long long sum=0;
void tryy(int k)
{
     if (k==n)
     {
        if (a[n]>=rest)
          sum++;
     }
     else
     {
        int i;
        for (i=0;i<=a[k];i++)
          if (rest>=i)
          {
             rest=rest-i;
             tryy(k+1);
             rest=rest+i;
          }
     }
}
int main ()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n>>m;
    int i;
    for (i=1;i<=n;i++)
      cin>>a[i];
    rest=m;
    tryy(1);
    cout<<sum%1000007;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
