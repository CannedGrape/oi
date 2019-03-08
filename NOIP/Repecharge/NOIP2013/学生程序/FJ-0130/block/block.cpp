#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int n,s=0,k=0,t=0;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++)
    scanf("%d",&h[i]);
    for(int i=0;i<n;i++)
    if(h[i]>s)
    s=h[i];
    for(int i=0;i<s;i++)
      {for(int j=0;j<n;j++)
        {if((h[j]-i)>0&&t==0)
        {t=1; k++;}
        else
        if(h[j]-i<=0)
        t=0;}
      t=0;}
    cout<<k;
    return 0;
}
