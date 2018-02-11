#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
int n,m,q;
int a[31][31]={};
int s1[501];
using namespace std;
int main()
{
freopen("puzzle.in","r",stdin); 
freopen("puzzle.out","w",stdout); 
int i,j,ex,ey,sx,sy,tx,ty,k1=0;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    scanf("%d",&a[i][j]);
    for(i=1;i<=q;i++)
    {scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
    if(sx==tx && sy==ty)
    {s1[i]=0;continue;}
    if(ex==tx && ey==ty && ((sx==tx-1 && sy==ty) || (sx==tx && sy==ty-1) || (sx==tx+1 && sy==ty) || (sx==tx && sy==ty+1)))
    {s1[i]=1;continue;}
    if(a[ex][ey]==0 || a[sx][sy]==0 || a[tx][ty]==0)
    {s1[i]=-1;continue;}
    if(a[tx+1][ty]==0)
    k1++;
    if(a[tx-1][ty]==0)
    k1++;
    if(a[tx][ty+1]==0)
    k1++;
    if(a[tx][ty-1]==0)
    k1++;                 
    if(k1>=3)
    {s1[i]=-1;k1=0;continue;}
    k1=0;
    if(a[sx+1][sy]==0)
    k1++;
    if(a[sx-1][sy-1]==0)
    k1++;
    if(a[sx][sy+1]==0)
    k1++;
    if(a[sx][sy-1]==0)
    k1++;                 
    if(k1>=3)
    {s1[i]=-1;k1=0;continue;}
    k1=0;
    s1[i]=2*(tx-sx)+(ty-sy);}
    for(i=1;i<q;i++)
    cout<<s1[i]<<endl;
    cout<<s1[q];
fclose(stdin);
fclose(stdout);
//system("pause");
   return 0; 
    }
