#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX (1000000)

int
   ch[MAX],
   a[MAX],
   b[MAX];
using namespace std;

int tz(int n)
{
    int
       x=0;
    for(int i=n;i>=0;i--)
    {
        if(ch[i]<0)
          return ch[i];
        else
          x=x+ch[i];
        
    }
    return x;
}

int fs(int n)
{
    int
       x=a[0]+b[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]+b[i]>x)
          x=a[i]+b[i];
    }
    return x;
}

int main()
{
    
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int
       n,
       p,
       big;
    scanf("%d %d",&n,&p);
    for(int i=0;i<n;i++)
    {
        cin>>ch[i];
    }
    for(int i=0;i<n;i++)
        a[i]=tz(i);
    b[0]=a[0];
    for(int i=1;i<n;i++)
        b[i]=fs(i);
    big=b[0];
    for(int i=1;i<n;i++)
    {
        if(big<b[i])
          big=b[i];
    }
    cout<<big%p;
    return 0;
}
