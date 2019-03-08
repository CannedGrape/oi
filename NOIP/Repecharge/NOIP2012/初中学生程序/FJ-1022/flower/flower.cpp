#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,a[101],ans,c[102],g;
void tryy(int k,int l)
{
     int i;
     if (k==m+1) {ans++; ans=ans%1000007; return;}
       for(i=l;i<=n;i++)
       {if(a[i]>0)
        if (c[i+1]+k+a[i]>=m)
         {
         a[i]--;
         tryy(k+1,i);
         a[i]++;
         }
       
     }
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++)cin>>a[i];
    
    for(i=n;i>0;i--) c[i]=c[i+1]+a[i];
    i=n; while(c[i]<m)i--; g=i;
    tryy(1,1);
    cout<<ans%1000007;
    fclose(stdin);
    fclose(stdout);
  //  system("pause");
    return 0;
}
