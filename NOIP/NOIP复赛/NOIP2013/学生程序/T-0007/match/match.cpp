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
//#define LOCAL
using namespace std;

#ifndef LOCAL
#define DEBUG
#endif

template <typename Type>
Type Max(Type x,Type y){
    return x>y?x:y;
}

template <typename Type>
Type Min(Type x,Type y){
    return x<y?x:y;
}

int main(){
    #ifdef DEBUG
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    #define LOCAL
    #endif
    //system("pause > nul");
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
