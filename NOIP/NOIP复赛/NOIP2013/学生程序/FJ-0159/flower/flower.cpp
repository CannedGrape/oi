#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int n,i,k,h[1000]={0},m=0,p=0;
    cin>>n;
    k=n;
    for(i=1;i<=n;i++)
    {
       cin>>h[i-n+k];
       if(h[i-n+k]==h[i-n+k-1])
          k--;
    }
    for(i=2;i<=k;i=i+2)
    {
       if(h[i]>h[i-1]&&h[i]>h[i+1])
       m++;
       if(h[i]<h[i-1]&&h[i]<h[i+1])
       p++;
    }
    if(m>p)
      k=2*m+1;
    else 
      k=2*p+1;
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
