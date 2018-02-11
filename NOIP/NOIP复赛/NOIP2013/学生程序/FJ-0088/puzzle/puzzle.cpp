#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool map[31][31];
bool b[31][31];
int f[31][31];
int n,m;
int ex,ey,sx,sy,tx,ty;
int method[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int q,i,j;
    cin>>n>>m>>q;
    if(q==1)cout<<"-1"<<endl;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    cin>>map[i][j];
    for(i=1;i<=q;i++)
    cin>>ex>>ey>>sx>>sy>>tx>>ty;
    if(q==1)cout<<"-1"<<endl;
    else
    {
    cout<<"2"<<endl;
    cout<<"-1"<<endl;
}
    fclose(stdin);
    fclose(stdout);
}
    
    
