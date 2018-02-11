#include<iostream>
#include<cstdio>
using namespace std;
int a[100100]={},n;
long long ans=0;
void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;++i)
             scanf("%d",&a[i]);
}
inline int my_function(int x)
{
       return x>=0 ? x : 0;
}
void work()
{
     for(int i=0;i<=n;++i)
             ans+=my_function(a[i+1]-a[i]);
     cout<<ans<<endl;
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    init();
    work();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
