#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[101],x[100],s,ans;
void tryy(int c)
{
     if(c==n)
       {
       if(m-s<=a[c])
         ans=(ans+1)%1000007;
       return;
       }
     for(int i=1;i<=m-s-n+c;i++)
       {
       s+=i;
       tryy(c+1);
       s-=i;
       }
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    tryy(1);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
