#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct block
{
      int h,l,r,i;
      }a[100001];
int cmp(const void *a,const void *b)
{
    block *c=(block *)a;
    block *d=(block *)b;
    if(c->h>d->h)return 1;
    else 
    return -1;
}  
int queue[100001];
int sum=0;
int main()
{
     freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {cin>>a[i].h;a[i].i=0;}
    int head,tail;
    int v,j;
    for(i=0;i<n;i++)
    {
    head=1;
    tail=1;queue[tail]=a[i].h;j=i;
    v=queue[head];
    while(j<=n&&queue[tail]>=v)
    {tail++;j++;queue[tail]=a[j].h;}
    a[i].r=j-1;
    head=1;
    tail=1;queue[tail]=a[i].h;j=i;
    v=queue[head];
    while(j>=0&&queue[tail]>=v)
    {tail++;j--;queue[tail]=a[j].h;}
    a[i].l=j+1;
    }
    qsort(a,n,sizeof(block),cmp);
    bool b;
    int maxn;
    for(i=0;i<n;i++)
    {
    b=false;
    maxn=100000;
    for(j=a[i].l;j<=a[i].r;j++)
    {if(a[j].h==a[j].i){maxn=0;break;}
    else maxn=min(maxn,a[j].h-a[j].i);}
    for(j=a[i].l;j<=a[i].r;j++)
    {a[j].i+=maxn;}
    sum+=maxn;
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
    
    
    
    
