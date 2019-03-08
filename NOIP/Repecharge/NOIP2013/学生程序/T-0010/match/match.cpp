#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100001],b[100001];
int n;
int check()
{
    int wysb=1;
    for(int i=1;i<=n;++i)
    if(a[i]!=b[i])wysb=0;
    return wysb;
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
    scanf("%d",&b[i]);
    for(int i=1;i<=n-1;++i)
    {
        swap(a[i],a[i+1]);
        if(check())
        {
            cout<<1;
            return 0;
        }
        swap(a[i],a[i+1]);
    }
    cout<<2;
    fclose(stdin);fclose(stdout);
}
    
