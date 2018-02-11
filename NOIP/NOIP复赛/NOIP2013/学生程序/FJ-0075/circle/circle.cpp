#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long N,M,K,X;
long long pow(long long a,long long b,long long mod){
           long long base=a,ret=1;
           while(b){
                    if(b&1)ret=(ret*(base%mod)%mod);
                    base=(base*base)%mod;
                    b>>=1;
                    }
           return ret;
}
int main(){
    freopen("circle.in","r",stdin);freopen("circle.out","w",stdout);
    cin>>N>>M>>K>>X;
    cout<<(X+((pow(10,K,N)*M)%N))%N<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}
