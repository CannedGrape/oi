#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,h[100010],num[100010],sz;
int ans,k;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d",&h[i]);
    h[0]=-1000;
    for(i=1;i<=n;i++)
    if(h[i]!=h[i-1])
    {sz++;num[sz]=h[i];}
    if(sz>0)
    {
         ans++;
         if(sz>1)
         {
             if(num[2]>num[1])  k=1; else k=0;
             ans++;
             for(i=3;i<=sz;i++)
             {
                 if(k==1 && num[i]<num[i-1])  {ans++;k=0;}
                 if(k==0 && num[i]>num[i-1])  {ans++;k=1;}  
             }
         }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
