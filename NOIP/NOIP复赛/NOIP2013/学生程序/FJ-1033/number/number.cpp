#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
long long maxn,maxj;
long long n,p,sum=0,a;
long long st[1000001]={},sp[1000001]={},mark[1000001];
int main()
{
    
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>p;
    
    for(long long i=1;i<=n;i++) 
     {cin>>st[i];
     if(st[i]+sp[i-1]>sp[i])sp[i]=st[i]+sp[i-1];
     else sp[i]=st[i];
     if(i==1){mark[1]=sp[1];maxn=mark[1]+sp[1];maxj=mark[1];}
     else
      {if(sp[i-1]+mark[i-1]>maxn)
         maxn=sp[i-1]+mark[i-1];
       mark[i]=maxn;
       if(maxj<mark[i]) maxj=mark[i];
      }
     }
    cout<<maxj%p;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
