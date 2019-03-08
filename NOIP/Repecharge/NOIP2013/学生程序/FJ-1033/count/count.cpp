#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
long int n,ans;
int x;
void find(int w)
{
     if(w%10==x) ans++;
     if(w/10>0) find(w/10);
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    
    
    cin>>n>>x;
    if(x==0) ans=0;
    else ans=1;
    for(int i=10;i<=n;i++)
       find(i);
    
    
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
