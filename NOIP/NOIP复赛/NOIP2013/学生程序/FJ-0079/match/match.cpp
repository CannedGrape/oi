/**************************
    noip2013 - Day1 - T2 match
    Author: RsEnts
**************************/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 200010

using namespace std;

struct Position {
    int val, pos;
}poss[2][MaxN];

int N, permu[MaxN], fpermu[MaxN], Tree[MaxN];
long long Ans;

int lowbit(int x) {
    return x & (-x);
}

bool cmp(Position a, Position b) {
    return a.val < b.val;
}

int Query(int i) {
    int ret = 0;
    for( ; i; i -= lowbit(i))
        ret += Tree[i];
    return ret;
}

void Modify(int i) {
    for( ; i <= N; i += lowbit(i))
        ++Tree[i];
}

int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    int i;
    scanf("%d", &N);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &poss[0][i].val);
        poss[0][i].pos = i;
    }
    for(i = 1; i <= N; ++i) {
        scanf("%d", &poss[1][i].val);
        poss[1][i].pos = i;
    }
    sort(poss[0] + 1, poss[0] + N + 1, cmp);
    for(i = 1; i <= N; ++i)
        permu[poss[0][i].pos] = i;
    sort(poss[1] + 1, poss[1] + N + 1, cmp);
    for(i = 1; i <= N; ++i)
        fpermu[i] = poss[1][permu[i]].pos;
    for(i = N; i; --i) {
        Ans += Query(fpermu[i]);
        Modify(fpermu[i]);
    }
    cout << Ans % 99999997 << endl;
    return 0;
}
