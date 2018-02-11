#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(int i = a;i <= b;++i)
using namespace std;
int   n,m;
int   trains  [1001][1001];
int   WYin;
bool  trabo   [1001][1001];
int   level   [1001];
bool  none;
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,m)
    {
        scanf("%d",&trains[i][0]);
        FOR(j,1,trains[i][0]) scanf("%d",&trains[i][j]),trabo[i][trains[i][j]] = true;
    }
    FOR(i,1,n)//level
    {
        none = false;
        FOR(j,0,n) ++level[j];
        FOR(j,1,m)
        {
            WYin = level[trains[j][1]];
            FOR(k,2,trains[j][0]) if (WYin > level[trains[j][k]]) WYin = level[trains[j][k]];
            FOR(k,trains[j][1],trains[j][trains[j][0]])
                if(level[k] >= WYin && trabo[j][k] == false){none = true;--level[k];}
        }
        if (!none) break;
    }
    printf("%d",level[0]);
    fclose(stdin);fclose(stdout);
    return 0;
}
