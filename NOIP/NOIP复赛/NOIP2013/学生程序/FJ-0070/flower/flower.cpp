#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;

int n,a[100050]={0},ans=2;

int main ()
{
    freopen ("flower.in","r",stdin);
    freopen ("flower.out","w",stdout);
    
    cin>>n;
    for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
    bool mark=false;
    int  temp=a[1];
    if (a[2]>a[1]) mark=1;
    for (int i=2;i<=n;i++)
         {
             if (mark)
             {
                 if (a[i]<temp) {ans++;temp=a[i];mark=0;}
                 else  temp=a[i];
             }
             else 
             {
                 if (a[i]>temp) {ans++;temp=a[i];mark=1;}
                 else temp=a[i];
             }
         }
    if (ans==2) ans=1;
    cout<<ans<<endl;
    
    //system("pause");
    return 0;
}
// ORZ LWH
// rp+=LWH_RP
// ORZ CLJ
// ORZ XJP 
