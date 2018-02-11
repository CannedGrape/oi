/* puzzle.cpp NOIP 2013 day2.C
   By Sweetdumplings @ FZYZ / Fudan University
   Orz WJMZBMR!
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>
#define MAXN 32
using namespace std;
int N,M,Q;
int Board[MAXN][MAXN];
int EX,EY,SX,SY,TX,TY,Ans;
map<long long,int> StaHash;
const int dxy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
long long BoardHash()
{
    long long ret=0;
    for (int i=1;i<=N;++i)
    {
        for (int j=1;j<=M;++j)
        {
            ret=ret*131+Board[i][j];
        }
    }
    return ret;
}

void Search(int Ex,int Ey,int Count)
{
    for (int i=0;i<4;++i)
    {
        int Wx=Ex+dxy[i][0],Wy=Ey+dxy[i][1];
        if ((Wx<1)||(Wx>N)||(Wy<1)||(Wy>M))continue;
        if (Board[Wx][Wy]==0) continue;
        swap(Board[Wx][Wy],Board[Ex][Ey]);
        if (Board[TX][TY]==3) 
        {
            if (Ans>Count+1) Ans=Count+1;
            swap(Board[Wx][Wy],Board[Ex][Ey]);
            return ;
        }
        long long bkdr=BoardHash();
        if (StaHash.find(bkdr)==StaHash.end())
        {
            StaHash[bkdr]=Count+1;
            Search(Wx,Wy,Count+1);
        }else
        {
            if (StaHash[bkdr]>Count+1)
            {
                StaHash[bkdr]=Count+1;
                Search(Wx,Wy,Count+1);
            }
        }
        swap(Board[Wx][Wy],Board[Ex][Ey]);
    }
}
void Solve()
{
    Ans=0x7fffffff;
    StaHash.clear();
    scanf("%d%d%d%d%d%d",&EX,&EY,&SX,&SY,&TX,&TY);
    Board[EX][EY]=2;
    Board[SX][SY]=3;
    if (Board[TX][TY]==3) 
    {
        puts("0");
        return ;
    }
    StaHash[BoardHash()]=0;
    Search(EX,EY,0);
    if (Ans!=0x7fffffff) printf("%d\n",Ans);
    else puts("-1");
    Board[EX][EY]=1;
    Board[SX][SY]=1;
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&N,&M,&Q);
    for (int i=1;i<=N;++i)
    {
        for (int j=1;j<=M;++j)
        {
            scanf("%d",&Board[i][j]);
        }
    }
    for (;Q;Q--)
    {
        Solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
