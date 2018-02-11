#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n1,m1,n,m,k,x,temp;
    scanf("%d%d%d%d",&n,&m,&k,&x);
    n1=n;
    m1=m;
    while (n1%m1!=0)
      {temp=m1;
       n1=n1%m1;
       m1=temp;
       if (m1>=n1) 
         {temp=n1;
          n1=m1;
          m1=temp;
         }
      }
    m1=n1;    
    n1=1;  
    while (k--)
      {n1*=10;
       if (n1>=m1) n1=n1%m1;
      }  
    n1=(n1*m)%n;  
    x=(x+n1)%n;
    printf("%d\n",x);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
