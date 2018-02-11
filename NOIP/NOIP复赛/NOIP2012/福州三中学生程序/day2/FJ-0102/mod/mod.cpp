#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
long long a,b,i=0;
bool flag=1;
int main(){
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    scanf("%lld%lld",&a,&b);
    if(a>(b/2)){a=b-a;flag=0;}
    while((i*b+1)%a!=0)i++;
    if(flag)printf("%lld\n",(i*b+1)/a);
    else printf("%lld\n",b-(i*b+1)/a);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
