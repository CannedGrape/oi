#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prine.out","w",stdout);
    long long n=0,maxx=0;
    cin>>n;
    bool numb[n+1];
    long long i=1,j=n,k=0;
    for(i=1;i<=n;i++)
      numb[i]=true;
    if(n%2==0)
      j=n/2;
    for(i=2;i<=j;i++)
      if(numb[i]==true)
      {
        if(n%i==0)
          if(maxx<i)
            maxx=i;
        for(k=1;k<=n;k++)
          if(i*k<=n)
            numb[k*i]=false;
          else
            break;
      }
    cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
