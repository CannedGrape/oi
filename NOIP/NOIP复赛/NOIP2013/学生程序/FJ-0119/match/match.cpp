#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define N 99999997
using namespace std;
int n,c,
    a[100001]={},a2[100001],
    b[100001]={},b2[100001];
long long s=0;
void qsorta(int h,int e)
{   int i=h,j=e,mid=a[(i+j)/2];
    while(i<j)
    {while (a[i]<mid)i++;
     while (a[j]>mid)j--;
     if(i<=j)
       {c=a[i];a[i]=a[j];a[j]=c;
        c=a2[i];a2[i]=a2[j];a2[j]=c;
        i++;j--;
       }
    }
    if(i<e)qsorta(h,j);
    if(j>h)qsorta(i,e);
}
void qsortb(int h,int e)
{   int i=h,j=e,mid=b[(i+j)/2];
    while(i<j)
    {while (b[i]<mid)i++;
     while (b[j]>mid)j--;
     if(i<=j)
       {c=b[i];b[i]=b[j];b[j]=c;
        c=b2[i];b2[i]=b2[j];b2[j]=c;
        i++;j--;
       }
    }
    if(i<e)qsortb(h,j);
    if(j>h)qsortb(i,e);
}
inline int abs(int a,int b)
{if (a>=b)return a-b;
 else return b-a;
}
int main()
{   freopen("match.in","r",stdin);freopen("match.out","w",stdout);
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
      {scanf("%d",&a[i]);
       a2[i]=i;b2[i]=i;
      }
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    qsorta(1,n);qsortb(1,n);
    for(i=1;i<=n;i++)s+=abs(a2[i],b2[i]);
    s=(s/2)%N;
    printf("%lld\n",s);
    fclose(stdin);fclose(stdout);
    return 0;
}
