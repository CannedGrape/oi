#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int mymin(int a,int b)
{
  return a<b?a:b;
}
int mymax(int a,int b)
{
  return a>b?a:b;
}
int main()
{
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  int n;
  scanf("%d",&n);
  int i,a[n];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  int j,x,dp[2][n+1],ans1,ans2;
  //大小大小的情况，最大长度为ans1 
  memset(dp,0,sizeof(dp));
  dp[0][1]=a[0];
  for(i=1;i<n;i++)
  {
    memset(dp[1],0,sizeof(dp[1]));
    dp[1][1]=dp[0][1]>a[i]?dp[0][1]:a[i];
    for(j=2;j<=i+1;j++)
      if(j%2)
      {
        x=mymin((dp[0][j-1]<a[i] && dp[0][j-1])?a[i]:2147483647,(dp[1][j-1]<a[i] && dp[1][j-1])?a[i]:2147483647);
        dp[1][j]=mymax(x==2147483647?0:x,dp[0][j]);
      }  
      else
      {
        dp[1][j]=mymin(dp[0][j]==0?2147483647:dp[0][j],dp[0][j-1]>a[i]?a[i]:2147483647);
        if(dp[1][j]==2147483647)
          dp[1][j]=0;
      }
    for(j=0;j<n+1;j++)
      dp[0][j]=dp[1][j];
  }
  for(ans1=n;ans1;ans1--)
    if(dp[0][ans1]) break;

  //小大小大的情况，最大长度为ans2 
  memset(dp,0,sizeof(dp));
  dp[0][1]=a[0];
  for(i=1;i<n;i++)
  {
    memset(dp[1],0,sizeof(dp[1]));
    dp[1][1]=dp[0][1]<a[i]?dp[0][1]:a[i];
    for(j=2;j<=i+1;j++)
      if(j%2==0)
      {
        x=mymin((dp[0][j-1]<a[i] && dp[0][j-1])?a[i]:2147483647,(dp[1][j-1]<a[i] && dp[1][j-1])?a[i]:2147483647);
        dp[1][j]=mymax(x==2147483647?0:x,dp[0][j]);
      }  
      else
      {
        dp[1][j]=mymin(dp[0][j]==0?2147483647:dp[0][j],dp[0][j-1]>a[i]?a[i]:2147483647);
        if(dp[1][j]==2147483647)
          dp[1][j]=0;
      }
    for(j=0;j<n+1;j++)
      dp[0][j]=dp[1][j];
  }
  for(ans2=n;ans2;ans2--)
    if(dp[0][ans2]) break;
  printf("%d",mymax(ans1,ans2));
//  system("pause");
  fclose(stdin);
  fclose(stdout);
  return 0;
}
