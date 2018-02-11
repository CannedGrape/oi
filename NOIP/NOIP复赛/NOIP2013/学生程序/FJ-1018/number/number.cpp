#include <cstdio>
#include <cstring>
#include <iostream>
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define MST(i,a) memset(i,a,sizeof(i))
using namespace std;

int n,p,topd;
int num   [1000001];
int dp    [1000001];
int sp    [1000001];
int score [1000001];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d%d",&n,&p);
    FOR(i,1,n) scanf("%d",&num[i]);
    FOR(i,1,n)
    {
        sp[i] = num[i];
        FOR(j,1,i - 1)
        {
           MST(dp,0);
           FOR(k,j,i)
           {
                dp[k-j+1] = (dp[k-j] + num[k]) % p;
                if (dp[k-j+1] > sp[i]) sp[i] = dp[k-j+1];
           }
        }
    }
    topd = score[1] = sp[1] % p;
    FOR(i,2,n)
    {
        score[i] = (score[1] *2) % p;
        FOR(j,2,i - 1)
            if ((score[j] + sp[j]) % p > score[i]) score[i] = (score[j] + sp[j]) % p;
        if (score[i] > topd) topd = score[i];
    }
    printf("%d",topd);
    fclose(stdin);fclose(stdout);
    return 0;
}
