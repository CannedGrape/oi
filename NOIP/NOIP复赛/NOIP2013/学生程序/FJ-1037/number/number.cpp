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
#define MAXN 1000000 + 1000
//#define LOCAL
using namespace std;

#ifndef LOCAL
#define DEBUG
#endif

typedef long long int64;

struct STR{
    int Number;
    int Value;
    int Have;
}List[MAXN];

int64 N,P,Answer=-MaxLongint;

template <typename Type>
Type Max(Type a,Type b){
    return a>b?a:b;
}

void Value_f(){
    int Vl=List[1].Number;
    List[1].Value=Vl;
    FOR(v,2,N){
        Vl+=List[v].Number;
        List[v].Value=Max(List[v-1].Value,Vl);
        if(Vl<0) Vl=0;
    }
}

void have(){
    List[1].Have=List[1].Value;
    List[2].Have=List[1].Have+List[1].Value;
    FOR(v,3,N){
        int MN=List[v-1].Have+List[v-1].Value;
        List[v].Have=Max(List[v-1].Have,MN);
    }
}

void print(){
    int MAXV=-MaxLongint;
    FOR(i,1,N) MAXV=Max(MAXV,List[i].Have);
    FOR(i,1,N) printf("%d %d %d\n",List[i].Number,List[i].Value,List[i].Have);
    MAXV%=P;
    printf("%d\n",MAXV);
}

int main(){
    #ifdef DEBUG
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    #define LOCAL
    #endif
    scanf("%lld%lld",&N,&P);
    FOR(i,1,N) scanf("%d",&List[i].Number);
    Value_f();
    have();
    print();
    //system("pause > nul");
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
