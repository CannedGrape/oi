#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
int last[5][100001];
int dp[100001][2][2];//dp(i,j,k)
int h[100001];
int n;
int max(int a,int b)
{
    if(a>=b)
      return a;
    else
      return b;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&h[i]);
    int temp=0;
    for(j=1;j<=n;j++)
    {
      memset(dp,0,sizeof(dp));
      dp[j][0][0]=0;
      dp[j][0][1]=0;
      dp[j][1][0]=1;
      dp[j][1][1]=1;
      memset(last,0,sizeof(last));
      last[1][j]=0;
      last[2][j]=0;
      last[3][j]=h[i];
      last[4][j]=h[i];
    for(i=j+1;i<=n;i++)
    {
         dp[i][0][0]=max(dp[i-1][1][0],dp[i-1][0][0]);
         dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][1]);
         last[1][i]=last[1][i-1];
         last[2][i]=last[2][i-1];
         if(h[i]<last[3][i-1])
         {
           dp[i][1][1]=dp[i-1][1][0]+1;
           last[4][i]=h[i];
         }
         else
           if(h[i]>last[4][i-1])
           {
             dp[i][1][0]=dp[i-1][1][1]+1;
             last[3][i]=h[i];
           }
    }
    if(dp[n][0][0]>temp)
       temp=dp[n][0][0];
    if(dp[n][0][1]>temp)
       temp=dp[n][0][1];
    if(dp[n][1][0]>temp)
       temp=dp[n][1][0];
    if(dp[n][1][1]>temp)
       temp=dp[n][1][1];
    }
    cout<<(n-temp)<<endl;
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
