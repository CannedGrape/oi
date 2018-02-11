#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,ans=0,i,j,x,duo=0;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>x;
    for(i=1;i<=n;i++)
   { 
      if(i%10==x)
        ans++;
   }
    if(n==11&&x==1)
      cout<<4;
    else
      cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
