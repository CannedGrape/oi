#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int i,j,k,n;
int a[1000001];
bool p[10000001];
int main()
{freopen("prime.in","r",stdin);
 freopen("prime.out","w",stdout);
 scanf("%d",&n);
 for(i=2;i<=sqrt(n);i++)
    {if(p[i]==0)
       {a[++a[0]]=i;
       if(n%i==0)
         break;
       }
     for(j=1;j<=a[0];j++)
        {p[i*a[j]]=1;
         if(i%a[j]==0)
           break;
        }
    }
 printf("%d\n",n/i);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
