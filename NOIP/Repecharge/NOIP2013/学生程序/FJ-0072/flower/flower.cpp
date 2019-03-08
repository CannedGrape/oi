#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define MAX_N 222222

using namespace std;

int n, depth, req;
int a[MAX_N];
int odd[MAX_N], even[MAX_N][2];

int main()
{
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    scanf("%d", &n);
    depth = 50000000 / n;
    req = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        odd[i] = 1;
        for (int j = max(1, i - depth); j < i; j++)
        {
            if (a[i] > a[j]) 
            {
                odd[i] = max(odd[i], even[j][0] + 1);
                even[i][1] = max(even[i][1], odd[j] + 1);
            }
            else if (a[i] < a[j]) 
            {
                odd[i] = max(odd[i], even[j][1] + 1);
                even[i][0] = max(even[i][0], odd[j] + 1);
            }
        }
        req = max(req, max(max(even[i][0], even[i][1]), odd[i]));
    }
    printf("%d\n", req);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
