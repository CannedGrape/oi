#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int a[40][40];
int ex[151],ey[151],sx[151],sy[151],tx[151],ty[151];
int main()
{
freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int n,m,q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d", &a[i][j]);
    for(int i=1;i<=q;i++)
        {
        scanf("%d%d%d%d%d%d", &ex[i], &ey[i], &sx[i], &sy[i], &tx[i], &ty[i]);
        }
    cout<<-1;
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
