#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    int n, m, count[1001]={}, s, x, max=0;
    freopen("level.in", "r", stdin);
    freopen("level.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d", &s);        
        for(int j=0; j<s; j++) scanf("%d", &x), count[x]++;
    }
    for(int i=0; i<=n; i++) if(count[i]>max) max=count[i];
    printf("%d\n", max);
    return 0;
}
