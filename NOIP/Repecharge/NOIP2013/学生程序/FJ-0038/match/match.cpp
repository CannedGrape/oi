#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=99999997;
int n,a[101000]={},b[101000]={},c[101000]={},d[101000]={};
int num_a[101000]={},num_b[101000]={},num_c[101000]={},num_d[101000]={};
int t[101000]={};
inline int lowbit(int x)
{
       return x&(x^(x-1));
}
inline void add(int r)
{
       while(r<=n)
       {
           ++t[r];
           r+=lowbit(r);
       }
}
inline int sum(int r)
{
       int s=0;
       while(r)
       {
           s+=t[r];
           r-=lowbit(r);
       }
       return s;
}
inline int find_pos(int *p,int v)
{
    int l=1,r=n;
    while(l!=r)
    {
        int mid=(l+r)>>1;
        if(v<=p[mid])
            r=mid;
        else
            l=mid+1;
    }
    return l;
}
void print(int *p)
{
     for(int i=1;i<=n;++i)
             cout<<p[i]<<' ';
     cout<<endl;
}
void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
     for(int j=1;j<=n;++j)
         scanf("%d",&b[j]);
     for(int i=1;i<=n;++i)
         c[i]=a[i];
     for(int j=1;j<=n;++j)
         d[j]=b[j];
     sort(c+1,c+n+1);
     sort(d+1,d+n+1);
     //print(c);
     //print(d);
     for(int i=1;i<=n;++i)
         num_a[i]=find_pos(c,a[i]);
     for(int j=1;j<=n;++j)
         num_b[j]=find_pos(d,b[j]);
     for(int i=1;i<=n;++i)
         num_c[num_a[i]]=i;
     for(int j=1;j<=n;++j)
         num_d[num_b[j]]=j;
     //print(num_a);
     //print(num_b);
     //print(num_c);
     //print(num_d);
     
}
void get_pos()
{
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int s=num_b[i];
        int pos=num_c[s];
        ans+=pos+sum(n)-sum(pos)-i;
        //cout<<pos+sum(n)-sum(s-1)<<endl;
        if(ans>=mod)
            ans-=mod;
        add(pos);
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    init();
    get_pos();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
