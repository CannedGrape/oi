#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long a[100001]={},b[100001]={},c[100001]={},d[100001]={};
long long i,j,k;
long long n,m=0,p,maxn;
int main()
{freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
 cin>>n>>p;
 for(i=1;i<=n;i++)
  cin>>a[i];
 b[1]=a[1];
 for(k=2;k<=n;k++)
 {maxn=-8799876;
  for(j=1;j<=k;j++)
  {m=0;
   for(i=j;i<=k;i++)
    {m+=a[i];
     if(m>maxn)
      maxn=m;
    }
   }
  b[k]=maxn;
 }
 maxn=-3543421;
 d[1]=a[1];
 d[2]=a[1]*2;
 for(i=3;i<=n;i++)
 {maxn=-3543421;
  for(j=1;j<i;j++)
   if(b[j]+d[j]>maxn)
    maxn=b[j]+d[j];
  d[i]=maxn;
  }
 maxn=-9812231;
 for(i=1;i<=n;i++)
  if(d[i]>=maxn)
   maxn=d[i];
 cout<<maxn%p;
 fclose(stdin);
 fclose(stdout);
 //system("pause");
 return 0;
}
