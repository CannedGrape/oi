#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,maxx=-1111111,i;
    long long int p;
    cin>>n>>p;
    int a[n+1],b[n+1],c[n+1];
    memset(a,-1111111,sizeof(a));
    memset(b,-1111111,sizeof(b));
    memset(c,-1111111,sizeof(c));
    for(i=0;i<n;i++)
      cin>>a[i];
    b[0]=a[0];
    for(i=1;i<n;i++)
    {
      if((b[i-1]+a[i])>b[i])
        b[i]=a[i]+b[i-1];
      else
        b[i]=a[i];
    }
    c[0]=b[0];
    for(i=1;i<n;i++)
      c[i]=b[i-1]+c[i-1];
    for(i=0;i<n;i++)
      if(maxx<c[i])
        maxx=c[i];
    cout<<maxx%p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
