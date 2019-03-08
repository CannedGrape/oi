#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
int n,m,k=0,a[1000];
using namespace std;
int del(int num,int k)
{
    int i,sum=0;
    if(k==0)
      return 1;
    if(num>n)
      return 0;
    for(i=0;i<=a[num];i++)
      if(k-i>=0)
        sum=(sum+del(num+1,k-i))%1000007;
      else
        break;
    return sum;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
     {
      cin>>a[i];
      k+=a[i];
     }
    k-=m;
    cout<<del(1,k)<<endl;
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0;
}

