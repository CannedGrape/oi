#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
int i,j,n,m,x,k,a[1000005];
bool p[1000005];
int main()
{freopen("circle.in","r",stdin);
 freopen("circle.out","w",stdout);
 scanf("%d%d%d%d",&n,&m,&k,&x);
 for(i=1;i<=k;i++)
    {m*=10;
     m%=n;
     if(p[m]==0)
       {p[m]=1;
       a[++a[0]]=m;
       }
     else
       {m=a[(k-1)%(i-1)+1];
        break;
       }
    }
 printf("%d\n",(x+m)%n);
 //system("pause");
 fclose(stdin);
 fclose(stdout);
 return 0;
}
