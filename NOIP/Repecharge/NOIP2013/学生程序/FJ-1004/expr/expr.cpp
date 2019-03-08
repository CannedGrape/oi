#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
long long i,j,k,n,x;
char z[5000001];
long long t(long long l,long long r)
{long long i;
 for(i=l;i<=r;i++)
    if(z[i]=='+')
      return t(l,i-1)+t(i+1,r);
 for(i=l;i<=r;i++)
    if(z[i]=='*')
      return t(l,i-1)*t(i+1,r);
 x=0;
 for(i=l;i<=r;i++)
    x=x*10+z[i]-'0';
 x%=10000;
 return x;
}
int main()
{freopen("expr.in","r",stdin);
 freopen("expr.out","w",stdout);
 scanf("%s",&z);
 printf("%d\n",t(0,strlen(z)-1));
 fclose(stdin);
 fclose(stdout);
 //system("pause");
 return 0;
}
