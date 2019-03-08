#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,ans=0;
long long a[100001],b[100001],c[100001];
long long abss(int i)
{
    if (i>=0)
      return i;
    else
      return -i;
      }
void solve(void)
{
     int i,j,temp;
     for (i=1;i<=n-1;i++)
       for(j=1;j<=n-i;j++)
       {
          temp=abss(a[j]-b[j+i])+abss(a[j+i]-b[j]);
          if (c[j]+c[j+i]>temp)
          {
            swap(a[j],a[j+i]);
            ans++;
            c[j]=abss(a[j]-b[j]);
            c[j+i]=abss(a[j+i]-b[j+i]);
            }
       }
       }
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
      int i;
      cin>>n;
      for (i=1;i<=n;i++)
          cin>>a[i];
      for (i=1;i<=n;i++)
      {
          cin>>b[i];
          c[i]=abss(a[i]-b[i]);
          }
      solve();      
      cout<<ans<<endl;
     fclose(stdin);
     fclose(stdout);
      return 0;
}
      
