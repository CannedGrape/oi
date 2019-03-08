#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int ans;
int n,x;

int c(int a)
{
    while(a)
    {
            int xx=a%10;
            a=a/10;
            if(xx==x) ++ans;
           }
}

int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&x);
    for(int i=1; i<=n; ++i) c(i);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
