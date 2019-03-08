#include<iostream>
using namespace std;
#include<cstdio>
int main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int n,h[100001];
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>h[i];
    if(n%2==1)cout<<n/2+1;
    else cout<<n/2;
    return 0;
}
