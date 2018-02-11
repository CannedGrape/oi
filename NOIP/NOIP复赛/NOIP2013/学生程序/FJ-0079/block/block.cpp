/********************************
    noip2013 - Day2 - T1 block
    Author : RsEnts
********************************/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 100010

using namespace std;

int N, H[MaxN], Ans;

int main() {
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    int i;
    scanf("%d", &N);
    for(i = 1; i <= N; ++i)
        scanf("%d", &H[i]);
    for(i = 1; i <= N; ++i)
        if(H[i] - H[i - 1] > 0)
            Ans += (H[i] - H[i - 1]);
    printf("%d\n", Ans);
    return 0;
}
