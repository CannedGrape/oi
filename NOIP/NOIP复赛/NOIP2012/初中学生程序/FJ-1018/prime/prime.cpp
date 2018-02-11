#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int main()
{
  freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  long long n,i,j,k,ans,pd;
  cin>>n;
  for(i=2;i<=n;i++)
    {
    k=0;
    for(j=2;j<i;j++)
      if(i%j==0)
        {
        k=1;
        break;
        }
    pd=0;
    if(k==0)
     { {
      ans=n/i;
      for(j=2;j<ans;j++)
        if(ans%j==0)
          {
          pd=1;
          break;
          }
      }
    if(pd==0)
      {
      cout<<ans<<endl;
      break;
      }}
    }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
