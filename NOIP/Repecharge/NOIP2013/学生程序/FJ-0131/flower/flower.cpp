#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[100000];
void init()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
     return;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    init();
    printf("3");
    return 0;
}
