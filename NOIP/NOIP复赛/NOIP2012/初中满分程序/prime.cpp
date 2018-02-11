#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
inline int zs(int x)
{
       int i;
       for(i=2;i<=sqrt(x);i++)
         if(x%i==0)
           return 0;
       return 1;
}
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    int i;
    scanf("%d",&n);
    for(i=2;i<sqrt(n);i++)
      if(n%i==0)
        if(zs(i)==1)
          if(zs(n/i)==1)
            {
             printf("%d\n",n/i);
             fclose(stdin);
             fclose(stdout);
             system("pause");
             return 0;
            }
}
