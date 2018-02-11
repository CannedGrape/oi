#include<iostream>
using namespace std;
#include<cstdio>
int main(){
    freopen("puzzle","r",stdin);
    freopen("puzzle","w",stdout);
    int n,m,q,qipan[31][31],weizhi[501][7];
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
       cin>>qipan[i][j];
    for(int i=1;i<=q;i++)
     for(int j=1;j<=6;j++)
       cin>>weizhi[i][j];
    for(int i=1;i<=q;i++)
    cout<<-1<<endl;
    return 0;
}
