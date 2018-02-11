#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[100001]={},n,s=0;
int main()
{   freopen("block.in","r",stdin);freopen("block.out","w",stdout);
    scanf("%d",&n);
    int i,maxx,sign=1,h;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    s=a[1];
    maxx=a[1];h=a[1];
    for(i=2;i<=n;i++)
       {if(a[i]>=a[i-1]&&sign==1)maxx=a[i];
        if(a[i]<a[i-1]&&sign==1){sign=-1;continue;}
        if(a[i]<=a[i-1]&&sign==-1)continue;
        if(a[i]>a[i-1]&&sign==-1)
          {s+=maxx-h;
           h=a[i-1];
           maxx=a[i];
           sign=1;
          }
       }
    s+=maxx-h;
    printf("%d\n",s);
    fclose(stdin);fclose(stdout);
    return 0;
}
