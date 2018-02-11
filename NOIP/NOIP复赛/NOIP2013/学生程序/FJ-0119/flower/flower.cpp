#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{   freopen("flower.in","r",stdin);freopen("flower.out","w",stdout);
    int n,j,s1=1,s2=1,i,a[100001]={};
    bool sign=true;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    i=2;
    while(i<=n&&a[i]<=a[i-1])i++;
    while(i<=n)
      {while(a[i]>=a[i-1]&&i<=n)i++;
       if(i>n)break;
       while(a[i]<=a[i-1]&&i<=n)i++;
       s1+=2;
      }
    i=2;
    while(i<=n&&a[i]>=a[i-1])i++;
    while(i<=n)
      {while(a[i]<=a[i-1]&&i<=n)i++;
       if(i>n)break;
       while(a[i]>=a[i-1]&&i<=n)i++;
       s2+=2;
      }
    if(s1>=s2)printf("%d\n",s1);
    else printf("%d\n",s2);
    fclose(stdin);fclose(stdout);
    return 0;
}
