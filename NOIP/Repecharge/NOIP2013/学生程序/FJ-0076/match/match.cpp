#include<cstdio>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
long long H1[100001]={},H3[10001]={};
int n,l=0,ans=0;
struct H
{
       int x,y;
}H2[100001]={},H4[100001]={};
bool cmp(H a,H b)
{
       return a.y>b.y;
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      {scanf("%lld",&H1[i]);
      H2[i].y=H1[i];
      H3[i]=H1[i];}
    for(int i=1;i<=n;i++)
      {scanf("%lld",&H2[i].y);
      H4[i].y=H2[i].y;
      H4[i].x=H2[i].x;
      }
    sort(H3,H3+n);
    sort(H4,H4+n,cmp);
    for(int i=1;i<=n-1;i++)
      if(H4[i].x!=H3[i])
        {
        for(int j=i+1;j<=n;j++)
          if(H4[i].x=H3[j])
            {l=H3[j];
            H3[j]=H3[i];
            H3[i]=l;
            ans++;
            }
            }
    printf("%d",ans%99999997);
    //system("pause");
    return 0;
}
