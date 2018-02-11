//block
#include<cstdio>
#include<cstring>
#define MAXN 100000

int N,top=0;
long long H[MAXN],Q[MAXN],ans=0;

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
            scanf("%lld",&H[i]);
            if(H[i]>Q[top])
            {
                           ans+=H[i]-Q[top];
                           Q[++top]=H[i];
            }
            else
            {
                int h=1,t=top;
                while(h<=t)
                {
                           int mid=(h+t)>>1;
                           if(Q[mid]<H[i]) h=mid+1;
                           else t=mid-1;
                }
                Q[h]=H[i];
                top=h;
            }
    }
    printf("%lld\n",ans);
    return 0;
}
