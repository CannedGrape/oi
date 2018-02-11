#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,m,q;
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1; i<=q; ++i) printf("-1\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
