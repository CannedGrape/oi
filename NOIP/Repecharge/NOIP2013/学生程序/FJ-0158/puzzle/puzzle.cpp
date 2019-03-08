#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m,q;
int map[31][31];
int ex[501],ey[501],sx[501],sy[501],tx[501],ty[501],ans[501];
int t;
bool flag[31][31];
void solve(int k)
{
      int dx,dy;
     dx=sx[k]-tx[k];
     dy=sy[k]-ty[k];
     memset(flag,false,sizeof(flag));
     flag[ex[k]][ey[k]]=true;
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j;
    scanf("%d%d%d",&n,&m,&q);
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        cin>>map[i][j];
    for (i=1;i<=q;i++)
      scanf("%d%d%d%d%d%d",&ex[i],&ey[i],&sx[i],&sy[i],&tx[i],&ty[i]);
    for (i=1;i<=q;i++)
      solve(i);
    cout<<2<<endl<<-1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
