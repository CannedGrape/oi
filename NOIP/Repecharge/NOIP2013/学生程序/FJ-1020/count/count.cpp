#include<iostream>
#include<cstdio>
using namespace std;
long long int ans=0,n,x,i,j;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>x;
    for(i=1;i<=n;i++)
    {
                     j=i;
                     do
                     {
                         if(j%10==x)ans++;
                         j/=10;
                     }
                     while(j>=10);
                     if(j%10==x)ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
