#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, x, tail, ans;
int a[1000010];

int main()
{
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    scanf("%d", &n);
    tail = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        while (x < a[tail]) tail--;
        if (x == a[tail])
        {
            ans++;
            tail--;
        }
        a[++tail] = x;
    }
    cout << n - ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
