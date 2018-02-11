#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
int n,m;
int a[101];
long long sum=0;
void bf(int s,int r)
{
     int i;
     if(s==n)
      {if(r<=a[n]) sum++; sum=sum%1000007;
       return;}
     for(i=1;i<=min(a[s],r-n+s);i++)
       bf(s+1,r-i);
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
      cin>>a[i];
    bf(1,m);
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}   
    
