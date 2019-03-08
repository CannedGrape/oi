#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
int b[30][30]={0};
void abs(int& ss)
{if(ss<0)ss=0-ss;}
int bs(int ex1,int ey1,int sx1,int sy1,int tx1,int ty1)
{
    int k;
    if(b[tx1+1][ty1]+b[tx1][ty1+1]+b[tx1-1][ty1]+b[tx1][ty1-1]<2)
    return -1;
    if(b[sx1+1][sy1]+b[sx1][sy1+1]+b[sx1-1][sy1]+b[sx1][sy1-1]<2)
    return -1;
    //if(b[ex1][ey1]==b[tx1][ty1])
    //return 0;
    if(b[ex1][ey1]==b[tx1][ty1]&&ex1+ey1+1==sx1+sy1)
    return 1;
    if(b[ex1][ey1]==b[tx1][ty1]&&ex1+ey1-1==sx1+sy1)
    return 1;
    if(ex1+ey1+1==tx1+ty1&&tx1+ty1-1==sx1+sy1)
    return 2;
    if(ex1+ey1-1==tx1+ty1&&tx1+ty1-1==sx1+sy1)
    return 2;
    if(ex1+ey1-1==tx1+ty1&&tx1+ty1+1==sx1+sy1)
    return 2;
    if(ex1+ey1+1==tx1+ty1&&tx1+ty1+1==sx1+sy1)
    return 2;
    k=abs(ex1+ey1-sx1-sy1)+5*abs(tx1+ty1+1-sx1-sy1);
    return k;
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int n,m,q,i,j;
    int ex,ey,sx,sy,tx,ty;
    cin>>n>>m>>q;
    int s[500];
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          cin>>b[i][j];
    for(i=1;i<=q;i++)
    {
       cin>>ex>>ey>>sx>>sy>>tx>>ty;
       s[i]=bs(ex,ey,sx,sy,tx,ty);
    }
    for(j=1;j<=q;j++)
       cout<<s[j]<<endl;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
