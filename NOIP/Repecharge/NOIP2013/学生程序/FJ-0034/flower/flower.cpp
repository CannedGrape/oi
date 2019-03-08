#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int h[100010],n,ans;
int main()
{
    int i,j;
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&h[i]);
    ans=1;
    i=1;
    while(h[i]>=h[i+1]&&i<n)
      i++;
    if(i==n)
       {if(h[1]!=h[i])
          cout<<2<<'\n';
        else
          cout<<1<<'\n';
        fclose(stdin);
        fclose(stdout);
        return 0;
       }
    if(h[1]==h[i])
      ans=1;
    else
      ans=2;
    while(i<n)
      {while(h[i]<=h[i+1]&&i<n)
         i++;
       if(i!=n)
         ans++;
       while(h[i]>=h[i+1]&&i<n)
         i++;
       if(i!=n)
         ans++;
      }
    ans++;
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
