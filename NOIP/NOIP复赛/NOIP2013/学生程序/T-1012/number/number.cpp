#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
int sum=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,p;
    cin>>n>>p;
    int a[4][1000]={ };
    for(int i=1;i<=n;i++)
       cin>>a[1][i];
    a[2][1]=a[1][1];
    a[3][1]=a[2][1];
    for(int i=2;i<=5;i++)
       {for(int j=1;j<=i;j++)
          {sum=a[1][j]+sum;}
       a[2][i]=sum;
       sum=0;}
    for(int j=2;j<=5;j++)
        a[3][j]=a[2][j-1]+a[3][j-1];
    for(int j=1;j<=5;j++)
      for(int i=1;i<=4;i++)
         if(a[3][i]<a[3][i+1])
            {sum=a[3][i];
            a[3][i]=a[3][i+1];
            a[3][i+1]=sum;}
    cout<<a[3][1]%p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}          
       
    
