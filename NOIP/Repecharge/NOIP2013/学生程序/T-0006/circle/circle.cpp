#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[2000002],l[2000002],r[2000002];

int Pow(long long b)
{
    long long s=1;
    for (int i=1; i<=b; ++i)
      s=s*10;
    return s;
}

int  main ()
{
     freopen("circle.in","r",stdin);
     freopen("circle.out","w",stdout);
     long long n,m,x,k,Mx,Max,MAx,Ans,Ak=0;
     scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&x);
     k=k%10;
     Max=Pow(k);
     while (Max>(n+m)) { Max/=10; }
     if (Max<10) Max=Max*10;
     for (int i=0; i<n; ++i)
       l[i]=i;
     for (int i=1; i<=Max; ++i)
       {
          Ans=0;
          for (int j=n-1; j>=m; --j)
            l[j]=l[j-m],r[l[j]]=j;
          while (l[n-1]+Ans+1<n && Ans<m )
            {
               l[Ans]=l[n-1]+Ans+1;
               r[l[Ans]]=Ans;
               ++Ans;
             }
        if (Ans<m) 
          while (Ans<m)
            {
              l[Ans]=Ak;
              r[l[Ans]]=Ans;
              ++Ans;
              ++Ak;
            }
        Ak=0;
      }
       printf("%d",r[x]);
     fclose(stdin); fclose (stdout);
}
