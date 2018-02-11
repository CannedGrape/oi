#include <iostream>
#include <cstdio>

using namespace std;

long long n, m, k, x, tmp;

long long pow(long long x)
{
    if (x == 0) return 1;
    if (x == 1) return 10 % n;
    long long tmp = pow(x / 2);
    tmp = (tmp * tmp) % n;
    if (x % 2 == 1) tmp = (tmp * 10) % n;
    return tmp;
}

int main()
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    cin >> n >> m >> k >> x;
    tmp = (pow(k) * m + x) % n;
    cout << tmp << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

