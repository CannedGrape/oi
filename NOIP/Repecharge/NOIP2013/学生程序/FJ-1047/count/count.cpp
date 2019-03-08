#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int k=i; 
        while(k)
        {
            if(k%10==m)sum++;
            k/=10;
        }
    }
    cout<<sum;
    fclose(stdin);fclose(stdout);
}
