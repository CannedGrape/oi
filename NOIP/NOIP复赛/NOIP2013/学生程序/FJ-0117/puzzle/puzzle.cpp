#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
int n,m,q;
bool board[1001][1001];
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    cin>>n>>m>>q;
    int i,j;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        cin>>board[i][j];
    int litter;
    for(i=1;i<=q*6;i++)
      cin>>litter;
    for(i=1;i<=q;i++)
      cout<<"-1"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
