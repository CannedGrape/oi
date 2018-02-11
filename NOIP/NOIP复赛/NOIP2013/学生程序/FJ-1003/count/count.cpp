#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,x,p;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;i++)
      {
       j=i;
       while(j>0)
         {
          if(j%10==x)
            p++;
          j/=10;
         }
      }
    printf("%d\n",p);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
