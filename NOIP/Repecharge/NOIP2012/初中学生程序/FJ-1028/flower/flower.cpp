#include<iostream>
#include<cstdio>
using namespace std;
int n=0,m=0,a[101]={},sum=0,f[101][101][101]={};
const int mod=1000007;
int main()
{   freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n>>m;
    int i=0,j=0,k=0,sum=0,l=0;
    for(i=1;i<=n;i++)
      cin>>a[i];
    for(j=0;j<=m;j++)
      f[0][j][0]=1;
    for(i=1;i<=n;i++)
      f[i][0][0]=1;
    for(j=0;j<=(a[1]<m?a[1]:m);j++)
      f[1][j][j]=1;
    for(i=2;i<=n;i++)
      {for(j=1;j<=m;j++)
         {for(l=0;l<=a[i-1];l++)
            {f[i][j][0]+=f[i-1][j][l];
             f[i][j][0]%=mod;
             f[i][j][1]+=f[i-1][j-1][l];
             f[i][j][1]%=mod;
            }
          for(k=2;k<=a[i];k++)
            f[i][j][k]=f[i][j-1][k-1]%mod;
         }
      }
    for(i=1;i<=n;i++)
      for(k=1;k<=a[i];k++)
        {sum+=f[i][m][k];
         sum%=mod;
        }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
