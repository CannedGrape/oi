#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct t{
       int body;
       int num;
       }a[100001];
t b[100001];
int ra[100001]={},rb[100001]={};
int cmp(const void *a, const void*b)
{
       return((*( t *)a).body < (*( t *)b).body);
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int l,i,n,j;
    long long ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {scanf("%d",&a[i].body);
    a[i].num=i;
    }
    for(i=0;i<n;i++)
    {scanf("%d",&b[i].body);
    b[i].num=i;
    }
    qsort(a,n,sizeof(t),cmp);
    qsort(b,n,sizeof(t),cmp);
    l=n;
    for(i=0;i<n;i++)
    {
    ra[a[i].num]=i;
    rb[b[i].num]=i;
    }
    for(i=0;i<n-1;i++)
    {
    if(b[ra[i]].num!=i)
    {
    ans+=b[ra[i]].num-i;
    for(j=i;j<b[ra[i]].num;j++)
    b[rb[j]].num++;
    }
    if(ans>99999997)
    ans=ans%99999997;
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;    
}
