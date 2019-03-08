#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,h[100001],i,j,s=0,t=0;
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
       cin>>h[i];
    j=1;
    while(j<=n)
      {
       if (h[j+1]==0) break;
       while(h[j]>=h[j+1]&&j<=n){s++;j++;}
       if(s>0) {t++;s=0;}
       while(h[j]<=h[j+1]&&j<=n){s++;j++;}
       if(s>0) {t++;s=0;}
      }
    cout<<t+1<<endl;
    return 0;
}
