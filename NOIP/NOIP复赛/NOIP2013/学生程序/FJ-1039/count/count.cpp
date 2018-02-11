#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,x;
int cnt(int a){
    short dgt[15];
    int diver=100000,i,sz=6;
    while(diver>a){
       diver/=10;
       sz--;
    }
    i=sz;
    while(diver>0){
       dgt[i]=a/diver;
       a-=dgt[i]*diver;
       i--;
       diver/=10;
    }
    int j;
    long long ans=0;
    for(j=1;j<=sz;j++){
       if(dgt[j]==x)ans++;
    }
    return ans;
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>x;
    int i;
    unsigned long long sum=0;
    for(i=1;i<=n;i++)
        sum+=cnt(i);
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
