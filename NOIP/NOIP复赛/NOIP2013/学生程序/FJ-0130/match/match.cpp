#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int p=0;
    long long s1,d1,s2,d2;
    int n;
    long long h=0;
    cin>>n;
    long long a[n][2];
    for(int i=0;i<2;i++)
      for(int j=0;j<n;j++)
      scanf("%lld",&a[j][i]);
    for(int i=0;i<n;i++)
      h=h+(a[i][0]-a[i][1])*(a[i][0]-a[i][1]);
      for(int j=0;j<n-1;j++)
      {s1=a[j][0];
      d1=a[j][1];
      s2=a[j+1][0];
      d2=a[j+1][1];
      if((s1-d1)*(s1-d1)+(s2-d2)*(s2-d2)>(s1-d2)*(s1-d2)+(s2-d1)*(s2-d1))
      {a[j][0]=s2;
      a[j+1][0]=s1;
      p++;}}
    printf("%d",p%99999997);
    return 0;
}
