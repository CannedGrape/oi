#include<cstdio>
#include<cstring>
#define MAXN 100010
#define max(a,b) a>b?a:b

int N,H[MAXN],F[MAXN][3],ans=1;

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
            scanf("%d",&H[i]);
            F[i][2]=1;
    }
    for(int i=2;i<=N;i++)
            for(int j=1;j<i;j++)
            {
                    if(H[j]<H[i])
                    {
                                F[i][0]=max(F[i][0],F[j][2]+1);
                                F[i][2]=max(F[i][2],F[j][1]+1);
                                ans=max(ans,F[i][0]);
                    }
                    else if(H[j]>H[i])
                    {
                         F[i][1]=max(F[i][1],F[j][2]+1);
                         F[i][2]=max(F[i][2],F[j][0]+1);
                         ans=max(ans,F[i][1]);
                    }
                    ans=max(ans,F[i][2]);
            }
    printf("%d\n",ans);
    return 0;
}
