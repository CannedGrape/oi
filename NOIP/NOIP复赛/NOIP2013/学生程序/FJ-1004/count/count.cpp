#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
int i,j,k,n,a,s;
int main()
{freopen("count.in","r",stdin);
 freopen("count.out","w",stdout);
 scanf("%d%d",&n,&a);
 for(i=1;i<=n;i++)
    {j=i;
     while(j!=0){if(j%10==a)s++;j/=10;}
    }
 printf("%d\n",s);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
