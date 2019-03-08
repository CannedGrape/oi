#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int i,j,k,n,s=1,a[100001];
int main()
{freopen("flower.in","r",stdin);
 freopen("flower.out","w",stdout);
 scanf("%d",&n);
 for(i=1;i<=n;i++)
    {scanf("%d",&a[i]);}
 for(i=2;i<=n-1;i++)
    if(a[i-1]>a[i]<a[i+1]||a[i-1]<a[i]>a[i+1])
      s++;
 printf("%d\n",s);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
