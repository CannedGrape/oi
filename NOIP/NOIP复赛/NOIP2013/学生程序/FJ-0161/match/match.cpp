#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<stdio.h>
long long n;
long long a[100000],b[100000],s=0;
using namespace std;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int i,j;
    scanf("%lld", &n);
    for(i=1;i<=n;i++)
      {
      scanf("%lld%lld", &a[i], &b[i]);
      }
    long long c[n+1],d[n+1];
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    for(i=1;i<=n-1;i++)
      {
      for(j=i;j<=n;j++)
        {
        if(a[i]<a[j])
          c[i]++;
        if(a[i]>a[j])
          c[j]++;
        }
      }
    for(i=1;i<=n-1;i++)
      {
      for(j=i;j<=n;j++)
        {
        if(b[i]<b[j])
          d[i]++;
        if(b[i]>b[j])
          d[j]++;
        }
      }
    for(i=1;i<=n;i++)
      {
      for(j=1;j<=n;j++)
        {
        if(c[i]==d[j])
          {
          s+=abs(i-j);
          if(i>j)
            {
            while(i>j)
              {
              swap(b[j],b[j+1]);
              j++;
              }
            }
          if(i<j)
            {
            while(j>i)
              {
              swap(b[j],b[j-1]);
              j--;
              }
            }
          }
        }
      }
    cout<<s;
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
