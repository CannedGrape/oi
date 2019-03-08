/**************************
    noip2013 - Day1 - T1 circle
    Author: RsEnts
**************************/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

long long P, m, k, x;

long long Power(long long a, long long b) {
    long long base = a % P, y = 1;
    for( ; b; b >>= 1) {
        if(b & 1)
            y = y * base % P;
        base = base * base % P;
    }
    return y;
}

int main() {
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    cin >> P >> m >> k >> x;
    cout << ((x + m * Power(10, k)) % P) << endl;
    return 0;
}
