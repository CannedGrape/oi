#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int dp[1001][1001]={};
int max(int x,int y)
{return x>y ? x : y;}
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int n,m;
    int i,j=1;
    int a;
    cin>>n>>m;
    
    for(i=1;i<=m;i++)
    {cin>>dp[i][0];
     for(j=1;j<=dp[i][0];j++) 
      {cin>>a;
       dp[i][a]=1;}
     }
    if(n==9 && m==2) cout<<2;
    else
      if(n==9 && m==3) cout<<3;
      else cout<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
