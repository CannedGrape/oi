#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[1000001],b[1000001];

int main ()
{
    freopen("block.in","r",stdin);    
    freopen("block.out","w",stdout);
    int n,m=0,F=1,L1,R1;
    long long Ans=0,Abs=0;
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
      scanf("%d",&a[i]),b[i]=a[i];
    L1=1; R1=n;
    a[0]=0; a[n+1]=0;
    sort(b+1,b+n+1);
    while (F!=0)
      {    
        Ans+=b[L1];
        a[L1]=a[L1]-b[L1];
        for (int i=L1+1; i<=R1; ++i)
          a[i]=a[i]-b[L1],b[i]=a[i];
        b[L1]=a[L1];
        sort(b+L1,b+R1);
        if (b[L1]==0)
        {
          F=0;
          for (int i=1; i<=n; ++i)
            {
             if (a[i-1]<=0 && a[i]>0) L1=i;
             if (a[i]>0 && a[i+1]<=0) { R1=i; F=1; break; }
            }
        }
      }
    cout<<Ans;
    fclose(stdin); fclose(stdout);
}
