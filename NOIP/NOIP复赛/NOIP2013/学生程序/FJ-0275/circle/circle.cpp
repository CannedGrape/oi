#include<iostream>
#include<cstdio>
using namespace std;

long long MOD(long long K,long long N)
{
    if(K==0)return 1;
    long long t=MOD(K/2,N);
    return K%2?(t*t%N*10)%N:(t*t)%N;
}

int main()
{
    freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	long long N,M,K,X;
    scanf("%lld%lld%lld%lld",&N,&M,&K,&X);
	printf("%lld\n",(X+M%N*MOD(K,N))%N);
    return 0;
}