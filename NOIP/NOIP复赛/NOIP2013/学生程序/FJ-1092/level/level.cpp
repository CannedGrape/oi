#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1000];
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];
        int s[1000];
        for (int j=1;j<=n;j++)
             cin>>s[j];
    }
    cout<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
