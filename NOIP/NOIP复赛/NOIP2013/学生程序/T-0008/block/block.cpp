#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,mn,mx,as,a[100002];
int Min(int a,int b) { return a<b?a:b; }
int Max(int a,int b) { return a>b?a:b; }
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    { 
        scanf("%d",&a[i]);
        mn=Min(mn,a[i]);
        mx=Max(mx,a[i]);
    }
    //for (int i=1; i<=n; ++i) a[i]-=mn;
    //mx-=mn;
    as=mn;
    for (int i=as+1; i<=mx; ++i)
    {
        int f=0;
        for (int j=1; j<=n; ++j)
            if (a[j]>=i){ 
              if (!f) ++mn,f=1;
            }
            else f=0;
    }
    printf("%d",mn);
    fclose(stdin); fclose(stdout);
}
