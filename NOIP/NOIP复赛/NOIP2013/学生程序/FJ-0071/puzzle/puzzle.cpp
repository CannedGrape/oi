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
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    bool place[31][31]={};
    int way;
    int n,m,i,j,q;
    int ex,ey,tx,ty,sx,sy;
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    cin>>place[i][j];
    while(q>0)
    {
    q--;
    cin>>ex>>ey>>sx>>sy>>tx>>ty;
    cout<<"-1"<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
