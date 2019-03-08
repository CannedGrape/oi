#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(int i = a;i <= b;++i)
using namespace std;

int n,x,d,s;
char num[1000];

int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&x);
    for(int i = x;i <= n;i+=10) ++d;
    for(int i = 10 * x;i <= n;i+=100) d+=10;
    for(int i = 100 * x;i <= n;i+=1000) d+=100;
    for(int i = 1000 * x;i <= n;i+=10000) d+=1000;
    for(int i = 10000 * x;i <= n;i+=100000) d+=10000;
    for(int i = 100000 * x;i <= n;i+=1000000) d+=100000;
    for(int i = 1000000 * x;i <= n;i+=10000000) d+=1000000;
    printf("%d",d);
    fclose(stdin);fclose(stdout);
    return 0;
}
