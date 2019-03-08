#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int comp(const void *a,const void *b)
{
    int *m=(int*)a,*n=(int*)b;
    return *m-*n;
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int n,a[10001],b[10001];
    cin>>n;
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    scanf("%d",&b[i]);
    double sum=0,ans=0;
    for(int i=1;i<=n;i++)
    sum+=(a[i]-b[i])*(a[i]-b[i]);
    qsort(a+1,n,sizeof(int),comp);
    qsort(b+1,n,sizeof(int),comp);
    for(int i=1;i<=n;i++)
    ans+=(a[i]-b[i])*(a[i]-b[i]);
    int x;
    if(a[n]>b[n])
    x=a[n];
    else
    x=b[n];
    sum-=ans;
    if((double)(sum/x)==(int)sum/x)
    cout<<(int)sum/x;
    else
    cout<<(int)sum/x+1;
}
