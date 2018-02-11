#include<cstdio>
int n,h[100001],ans=0;
int minn(int a,int b)
{
    return a<b?a:b;
}
void work(int l,int r)
{
     int mid=(l+r)/2;
     if(l==r)
     {
         ans+=h[l];
         return;
     }
     work(l,mid);
     work(mid+1,r);
     ans-=minn(h[mid+1],h[mid]);
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&h[i]);
    work(1,n);
    printf("%d\n",ans);
    return 0;
}
