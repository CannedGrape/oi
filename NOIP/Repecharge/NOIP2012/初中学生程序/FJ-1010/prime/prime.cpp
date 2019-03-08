#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
bool ss(int x)
{
     for(int i=2;i<=sqrt(x);i++)
       if(x%i==0)
         return false;
     return true;
}
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    scanf("%d",&n);
    for(int i=int(sqrt(n));i>=2;i--)
      if(n%i==0 && ss(i))
        {
        printf("%d\n",i);
        fclose(stdin);
        fclose(stdout);
        return 0;
        }
}
