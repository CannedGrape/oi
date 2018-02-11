#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    long long n,m,k,x;
    cin>>n>>m>>k>>x;
    if(n%10==0)
    {
    cout<<x;
    return 0;
    }
    int ans=1;
    for(int i=1;i<=k;i++)
    {
            ans*=10;
            ans%=n;
            //cout<<i<<" "<<ans<<endl;
    }
    cout<<(ans*m+x)%n<<endl;
}
