/* block.cpp NOIP 2013 day2.A
   By Sweetdumplings @ FZYZ / Fudan University
   Orz WJMZBMR!
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
#define MAXN 100002 
int H[MAXN];
int N;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&N);
    for (int i=1;i<=N;++i)
    {
        scanf("%d",&H[i]);
    }
    int T=0;
    long long Ans=0;
    for (int i=1;i<=N;++i)
    {
        if (H[i]>=T)
        {
            Ans+=H[i]-T;
            T=H[i];
        }else
        {
            T=H[i];
        }
    }
    cout <<Ans <<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
};
