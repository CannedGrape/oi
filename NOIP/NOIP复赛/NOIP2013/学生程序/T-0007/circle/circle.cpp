#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FOT(i,a,b) for(int i=a;i>=b;--i)
#define MST(a,b) memset(a,b,sizeof(a))
#define MaxLongint 0x7fffffff
//#define LOCAL//<<=============================================================极 限 数 据 秒 出
using namespace std;//<<========================================================来 对 拍 吧 骚 年 

#ifndef LOCAL
#define DEBUG
#endif

typedef unsigned long long int int64;

int64 Answer;
int64 N,M,X,K;
int64 times,Total=1;
bool Mod[1048576];

template <typename Type>
Type Max(Type x,Type y){
    return x>y?x:y;
}

template <typename Type>
Type Min(Type x,Type y){
    return x<y?x:y;
}

template <typename Type>
Type Gcd(Type n,Type m){
    return n%m==0?m:Gcd(m,n%m);
}

int main(){
    #ifdef DEBUG
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    #define LOCAL
    #endif 
    scanf("%lld%lld%lld%lld",&N,&M,&K,&X);
    times=N/Gcd(N,M);
    MST(Mod,false);
    Mod[0]=true;
    FOR(i,1,K){
        Total*=10;
        Total%=times;
        if(Mod[Total]) break;
        Mod[Total]=true;
    }
    Answer=X;
    FOR(i,1,Total){
        Answer+=M;
        Answer%=N;
    }
    printf("%lld\n",Answer);
    //system("pause > nul");
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif   
    return 0;
}
