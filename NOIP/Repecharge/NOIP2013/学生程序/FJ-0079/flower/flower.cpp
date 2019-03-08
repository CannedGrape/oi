/********************************
    noip2013 - Day2 - T2 flower
    Author : RsEnts
********************************/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 1000050

using namespace std;

int N, H[MaxN], f[MaxN][2], MaxV = 1000010, Ans;

int lowbit(int x) {
    return x & (-x);
}

int Max(int a, int b) {
    return a > b ? a : b;
}

void Modify(int i, int cas, int val) {
    if(cas == 0) {
        for(; i <= MaxV; i += lowbit(i))
            f[i][cas] = Max(f[i][cas], val);
    }
    if(cas == 1) {
        for(; i; i -= lowbit(i))
            f[i][cas] = Max(f[i][cas], val);
    }
}

int Query(int i, int cas) {
    int ret = -1000000000;
    if(cas == 0) {
        for( ; i; i -= lowbit(i))
            ret = Max(ret, f[i][cas]);
    }
    if(cas == 1) {
        for( ; i <= MaxV; i += lowbit(i))
            ret = Max(ret, f[i][cas]);
    }
    return ret;
}

int main() {
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    int i;
    scanf("%d", &N);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &H[i]); H[i] += 2;
    }
    memset(f, 192, sizeof(f));
    Modify(1, 0, 0); Modify(MaxV, 1, 0);
    for(i = 1; i <= N; ++i) {
        int f1 = Query(H[i] - 1, 0), f2 = Query(H[i] + 1, 1);
        ++f1; ++f2;
        Ans = Max(Ans, f1); Ans = Max(Ans, f2);
        Modify(H[i], 0, f2); Modify(H[i], 1, f1);
    }
    printf("%d\n", Ans);
    return 0;
}
