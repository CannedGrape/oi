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
//#define LOCAL
using namespace std;

#ifndef LOCAL
#define DEBUG
#endif

int Answer=0;
int N,C;

void Chenk(int i){
    while(i){
        if(i%10==C) Answer++;
        i/=10;
    }
}

int main(){
    #ifdef DEBUG
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    #define LOCAL
    #endif
    scanf("%d%d",&N,&C);
    FOR(i,C,N) Chenk(i);
    printf("%d\n",Answer);
    //system("pause > nul");
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
