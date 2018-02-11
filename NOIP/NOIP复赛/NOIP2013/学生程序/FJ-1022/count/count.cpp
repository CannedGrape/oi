#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    
    int n,x,cir,temp,ans=0;
    
    cin>>n>>x;
    for(cir=1;cir<=n;cir++)
    {
     temp=cir;
     while(temp)
     {
      if(temp%10==x) ans++;
      temp/=10;           
     }                      
    }
    
    cout<<ans;
    
    fclose(stdin);
    fclose(stdout);
    return 0;    
}
