#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    long long ans=0;
    int a[100001]={};
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    scanf("%d",&a[i]);
    if(a[i]>a[i-1])
    ans+=a[i]-a[i-1];
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
