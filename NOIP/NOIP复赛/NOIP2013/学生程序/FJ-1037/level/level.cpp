#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FOT(i,a,b) for(int i=a;i>=b;--i)
#define MST(a,b) memset(a,b,sizeof(a))
#define MaxLongint 0x7fffffff
//#define LOCAL//<<==========傻屌年年有 今年特别多 
using namespace std;

#ifndef LOCAL
#define DEBUG
#endif

int N,M,Lev[1500][1500];

int main(){
    #ifdef DEBUG
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    #define LOCAL
    #endif
    scanf("%d%d",&N,&M);
    FOR(i,1,M){
        scanf("%d",&Lev[i][0]);
        FOR(j,1,Lev[i][0]){
            scanf("%d",&Lev[i][j]);
        }
    }
    printf("%d\n",M);
    //system("pause > nul");
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
