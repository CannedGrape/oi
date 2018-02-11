#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<algorithm>
#define N 1000500
using namespace std;
int n,h[N];
long long f[N];
int main()
{
    freopen("block.in","r",stdin);freopen("block.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
     scanf("%d",&h[i]);
    for(int i=1;i<=n;i++)
    if(h[i]>h[i-1]) f[i]=(f[i-1]+h[i]-h[i-1]);
    else f[i]=f[i-1];
    cout<<f[n];
    fclose(stdin);fclose(stdout);
    return 0;
    }
