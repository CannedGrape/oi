#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,map[10001][101][2],x,sum;
void tryy(int c,int h)
{
     if(c>n)
       return;
     int bz=0,i=0;
     sum+=map[c][h][1];
     sum%=20123;
     while(bz<map[c][h][1])
       {
       if(map[c][(h+i)%m][0])
         bz++;
       i++;
       }
     tryy(c+1,(h+i-1)%m);
}
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=0;j<m;j++)
        for(int k=0;k<2;k++)
          cin>>map[i][j][k];
    cin>>x;
    tryy(1,x);
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
