#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int compare(const void *a,const void*b)
{
    return(*(int*)a-*(int*)b);
}
long long a[100000],b[100000],c[100000]={},d[100000]={},tol=0;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    unsigned int i,j,n,t;
    cin>>n;
    for(i=1;i<=n;i++)
      {
       cin>>a[i];
       c[i]=a[i];
      }
    for(i=1;i<=n;i++)
      {
       cin>>b[i];
       d[i]=b[i];
       }
    qsort(c,n+1,sizeof(long long),compare);
    qsort(d,n+1,sizeof(long long),compare);
    for(i=1;i<=n;i++)
     {
       j=1;
       while(c[j]!=a[i])
         j++;
       a[i]=j;
       j=1;
       while(d[j]!=b[i])
         j++;
       b[i]=j;
     }
    for(i=1;i<=n;i++)
      {
        if(a[i]!=b[i])
          {
            j=i+1;
            while(b[j]!=a[i])
              j++;
            t=b[i];
            b[i]=b[j];
            b[j]=t;
            tol++;
          }
      }
    cout<<tol<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
