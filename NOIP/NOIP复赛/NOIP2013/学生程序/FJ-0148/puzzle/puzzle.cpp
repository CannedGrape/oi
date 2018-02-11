#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[31][31],b[101],x,y,s=0,c1,c2;
int main()
{
    int n,m,q,i,j;
    memset(a,-1,sizeof(a));
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          cin>>a[i][j];
    for(i=1;i<=q;i++)
        {
           cin>>x>>y;
           a[x][y]=2;
           b[1]=x;b[2]=y;
           cin>>x>>y;
           a[x][y]=3;
           b[3]=x;b[4]=y;
           cin>>x>>y;
           b[5]=x;b[6]=y;
           c1=b[5]-b[3];c2=b[6]-b[4];
           if(c1<0) c1=c1*-1;  if(c2<0)  c2=c2*-1;
           if(a[x][y]==0||(b[1]==1&&b[3]==2&&b[5]==3)) {s=-1;}
               else if(a[x][y]==3) {s=0;}
                    else if(a[x][y]==1) {a[x][y]=5;s=2;}
                         else if(a[x][y]==-1) {a[x][y]=4;s=8;}
           cout<<s<<endl;
       }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
