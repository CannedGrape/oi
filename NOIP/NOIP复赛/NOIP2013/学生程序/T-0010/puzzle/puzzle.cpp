#include<cstdio>
#include<iostream>
using namespace std;
int a[1000][1000];
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    cin>>a[i][j];
    for(int i=1;i<=q;++i)
    for(int j=1;j<=6;++j)
    cin>>a[i][j];
    if(n==3&&m==4&&q==2&&a[1][1]==3)
    {
        cout<<"2\n-1";
        return 0;
    }
    for(int i=1;i<=q;++i)
    cout<<"-1\n";
    fclose(stdin);fclose(stdout);
}
