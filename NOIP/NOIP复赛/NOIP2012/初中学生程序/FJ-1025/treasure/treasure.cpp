#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;
long int a[10002][102];
bool pass[10002][102];
long int b[10002];
int n,m,begin;
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    memset(a,0,sizeof(a));
    memset(pass,0,sizeof(pass));
    long int  i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
     for(j=0;j<=m-1;j++)
     {
        cin>>pass[i][j];
        cin>>a[i][j];
        if(pass[i][j]==true)
          b[i]++;
     }
    cin>>begin;
    long int now=1;
    long int ans=0;
    while(now<n+1)
    {
        ans=ans+a[now][begin];          
        if(pass[now][begin]==true)
        {
          now++;
        }
        else
        {
            long int tot=a[now][begin]%b[now];
            while(tot!=0)
          {
              if(begin==m-1)
                begin=0;
              else
                begin++;
              if(pass[now][begin]==true)
                tot--;
          }
          now++;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
