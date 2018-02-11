#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    int n, x, count=0;
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    scanf("%d %d", &n, &x);
    for(int i=1; i<=n; i++) for(int j=i; j!=0; j/=10) if(x==j%10) count++;
    printf("%d\n", count);
    return 0;
}
