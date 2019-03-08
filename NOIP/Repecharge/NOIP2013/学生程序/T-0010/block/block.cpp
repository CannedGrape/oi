#include<cstdio>
#include<iostream>
using namespace std;
int a[100001];
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int n;
    cin>>n;
    int Max=-2147483647;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        Max=a[i]>Max?a[i]:Max;
    }
    a[0]=-1;
    int ans=0;
    for(int i=0;i<=Max;++i)
    for(int j=1;j<=n;++j)
    if(a[j]>=i&&a[j-1]<i)++ans;
    cout<<ans-1;
    fclose(stdin);fclose(stdout);
}
