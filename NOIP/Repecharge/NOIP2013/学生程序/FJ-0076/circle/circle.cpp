#include<cstdio>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int q[100000]={};
int main()
{
    int n,m,k,x,i;
    long long c,y=10,minn,ans;
    bool f=true;
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    for(int i=1;i<=10;i++)
      {
      if(y>n)break;
      y*=10;
      }
    q[1]=y;
    for(int i=2;i<=k;i++)
      {q[i]=(q[i-1]*10)%n;
      for(int j=1;j<=i-1;j++)
        if(q[i]==q[j])
          f=false;
      if(f==false)
        break;
      }
    if(k>i)
    k=k%(i-1);
    ans=((q[k]*m)%n+x)%n;
    printf("%d\n",ans);
    //system("pause");
    return 0;
}
