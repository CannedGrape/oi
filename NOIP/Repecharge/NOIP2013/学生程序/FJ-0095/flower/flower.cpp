#include<iostream>
#include<stdio.h>
using namespace std;
int n,a[100010];
void init()
{
     scanf("%d",&n);
     int i;
     for(i=1;i<=n;i++) scanf("%d",&a[i]);
}
int plan_A()
{
     int i,ans=1,num=a[1];
     for(i=2;i<=n;i++)
     {
       if(ans%2)
       {
         if (a[i]<num) num=a[i];
          else
          {
              ans++;
              num=a[i];
          }
       }
       else
       {
           if (a[i]>num) num=a[i];
          else
          {
              ans++;
              num=a[i];
          }
       }
     }
     return ans;
}
int plan_B()
{
     int i,ans=1,num=a[1];
     for(i=2;i<=n;i++)
     {
       if(ans%2)
       {
         if (a[i]>num) num=a[i];
          else
          {
              ans++;
              num=a[i];
          }
       }
       else
       {
           if (a[i]<num) num=a[i];
          else
          {
              ans++;
              num=a[i];
          }
       }
     }
     return ans;
}
int main()
{
    
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    
    init();
    cout<<max(plan_A(),plan_B())<<endl;
    return 0;
}

/*
5
5 3 2 1 2
*/
