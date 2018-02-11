#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,temp=1,a[100001];
long long ans=0;
bool b[100001];
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    memset(b,true,sizeof(b));
    memset(a,0,sizeof(a));
   cin>>n;
    int i;
    for(i=1;i<=n;i++)
   cin>>a[i];
   while(temp<=n)
   {
    i=temp;
   while(b[i]==true)
   {
      a[i]=a[i]-1;
      if(a[i]==0)
      {
          b[i]=false;
      }
      i++;
    }
    ans++;
    while(b[temp]==false)
    temp++;
    }
    cout<<ans;
    fclose(stdin);
   fclose(stdout);
   return 0;
}

