#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;
long long n,m,x,k;
long long shimi(long long t){
     long long i,j,ans;
     i=t;
     j=10;
     ans=1;
     while (i!=0){
           if (i&1) ans=(ans*j)%n;
           i>>=1;
           j=(j*j)%n;
     }
     return ans;
}
int main(){
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&x);
    long long ans;
    ans=(x+(m*shimi(k)%n))%n;
    printf("%I64d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
