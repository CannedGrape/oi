#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long x=0,n=0,m=0;
long long rx[100001][1001]={};
long long lu[100001][1001]={};
bool rb[100001][1001]={};
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    int i=0,j=0,lr=0,tl=0,b=0;
    cin>>n>>m;
    for(i=0;i<n*m;i++)
    {
      cin>>rb[i/m+1][i%m]>>rx[i/m+1][i%m];
      if(rb[i/m+1][i%m]==1)
      {
        lu[i/m+1][0]++;
        lu[i/m+1][lu[i/m+1][0]-1]=i%m;
      }
    }
    cin>>lr;
    while(tl<n)
    {
      tl++;
      x+=rx[tl][lr];
      b=rx[tl][lr];
      for(j=0;j<m;j++)
        if((lu[tl][j+1]<lr)&&(lu[tl][j+2]>=lr))
          break;
      lr=lu[tl][j+2];
      lr=lu[tl][rx[tl][b]%lu[tl][0]];
    }
    cout<<x%20123;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
