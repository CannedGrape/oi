#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
long long n;
bool judge(long long x)
{
     long long j;
     for(j=2;j<=x/2;j++)
       if(x%j==0)
         return false;
     return true;
}
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    cin>>n;
    long long i;
    for(i=2;i<=sqrt(n);i++)
      if(judge(i)&&(n%i==0&&judge(n/i))){
        cout<<n/i<<endl;
        break;
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
