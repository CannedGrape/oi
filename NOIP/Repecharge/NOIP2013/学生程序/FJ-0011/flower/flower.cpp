/* flower.cpp NOIP 2013 day2.B 
   By Sweetdumplings @ FZYZ / Fudan University
   Orz WJMZBMR!
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100002
int H[MAXN];
int F[MAXN][2],G[MAXN][2];
int N;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&N);
    for (int i=1;i<=N;++i)
    {
        scanf("%d",&H[i]);
    }
    memset(F,200,sizeof(F));
    memset(G,200,sizeof(G));
    // F : odd is small
    // G : odd is large
    int Ans=0;
    for (int i=1;i<=N;++i)
    {
        F[i][1]=1;
        G[i][1]=1;
        for (int j=0;j<i;++j)
        {
            if (H[i]>H[j])
            {
                if (F[i][0]<F[j][1]+1)
                {
                    F[i][0]=F[j][1]+1;
                }
                if (G[i][1]<G[j][0]+1)
                {
                    G[i][1]=G[j][0]+1;
                }
            }
            if (H[i]<H[j])
            {
                if (F[i][1]<F[j][0]+1)
                {
                    F[i][1]=F[j][0]+1;
                }
                if (G[i][0]<G[j][1]+1)
                {
                    G[i][0]=G[j][1]+1;
                }
            }
        }
        if (F[i][0]>Ans) Ans=F[i][0];
        if (F[i][1]>Ans) Ans=F[i][1];
        if (G[i][0]>Ans) Ans=G[i][0];
        if (G[i][1]>Ans) Ans=G[i][1];
    }
    printf("%d\n",Ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
