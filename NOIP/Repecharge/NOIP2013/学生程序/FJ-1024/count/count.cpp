#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    long long n,x,i,k,s=0;
    cin>>n>>x;
    for(i=1;i<=n;i++)
    {
        k=i;
        while(k!=0)
        {
            if(k%10==x)
                s++;
            k=k/10;
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
