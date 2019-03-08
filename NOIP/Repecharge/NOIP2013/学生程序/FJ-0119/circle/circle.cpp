#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,k,x;
long long ksm(int a,int b)
{   long long r=1,base=a%n;
    while(b!=0)
      {if(b%2)
         r=(r*base)%n;
       base=(base*base)%n;
       b=b/2;
      }
    return r;
}
int main()
{   freopen("circle.in","r",stdin);freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    m=m%n;long long s;
    s=(m*ksm(10,k)+x)%n;
    s=int(s);
    printf("%d\n",s);
    fclose(stdin);fclose(stdout);
    return 0;
}
