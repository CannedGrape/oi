#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    long long i,n,p;
    cin>>n;
    if ((n-1)%2==0)
      p=n-2;
    else
      p=n-1;
    for (i=p;i>=sqrt(n);i-=2)
    {
      if (n%i==0)
      {
        cout<<i;
        break;
      }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
