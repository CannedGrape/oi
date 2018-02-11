#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int
       n,
       x,
       count=0;
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++)
    {
        if(i%10==x)
          count++;
        for(int j=1;j<=i;j=j*10)
        {
            
            if(i/j%j==x)
              count++;
        }
    }
    printf("%d",count);
    return 0;
}
