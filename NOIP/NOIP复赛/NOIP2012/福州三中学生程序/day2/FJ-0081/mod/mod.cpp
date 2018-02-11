#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
using namespace std;
long long a,b,ans=0;
void mainn()
{
    long long i;
    i=b*2;
    ans=i/a;
    i=i%a;
    if (i==0) i=a;
    long long j;
    j=b%a;
    while ((i+1)%a!=0)
    {
        if ((a-i)/j>1)
        {
            ans+=((a-i)/j);
            i=a-((a-i)%j);
        }
        else
        {
            i+=b;
            ans+=i/a;
            i=i%a;
        }
    }
    if (i!=0) ans++;
    cout<<ans<<endl;
}
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    cin>>a>>b;
    a=a%b;
    if (a==b-1)
    {
        cout<<a<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if (a==1)
    {
        cout<<1<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    mainn();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
