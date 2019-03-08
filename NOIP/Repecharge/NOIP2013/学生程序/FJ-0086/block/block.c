#include<stdio.h>
#define min(a,b)a<b?a:b
int n,h[100005]={0},zero=0;
long long ans=0;
void seek()
{
     int l=1,r=n,k,minh=999999,i;
     while(l<=r)
     {
         while(h[l]==0){l++;if(l>n)return;}
         minh=h[l];i=l;
         while(h[i+1]!=0)
         {
             i++;
             if(h[i]<minh)
             {
                 minh=h[i];
             }
         }
         ans+=minh;
         for(k=l;k<=i;k++)
         {
             h[k]-=minh;
             if(h[k]==0)zero++;
             if(zero==n)return;
         }
         l=i+2;
     }
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        if(h[i]==0)zero++;
    }
    while(zero!=n)
    seek();
    printf("%lld",ans);
    return 0;
}

    
