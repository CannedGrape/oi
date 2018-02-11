#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;

int n,ans=0;
int a[100050]={0};

int main ()
{
    freopen ("block.in","r",stdin);
    freopen ("block.out","w",stdout);
    
    cin>>n;
    
    for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
    
    for (int i=1;i<=n;i++)
        if (a[i])
        {
            if (a[i+1]==0) {ans+=a[i];a[i]=0;}
            while (a[i])
            {
                   a[i]-=1;
                   int j=i+1;
                   while (a[j])
                   {
                       a[j]-=1;
                       j++;
                   }
                   ans++;
            }
        }
    
    cout<<ans<<endl;
    
    //system("pause");
    return 0;
}
//ORZ WJMZBMR 
//ORZ zanoes
//ORZ LWH 
//RP++
