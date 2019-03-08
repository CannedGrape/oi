#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    long long n,i,f=0,x;
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>x;
    for(i=0;i<=n;i++){
        if(i%10==x)
            f++;
        if(i>=10 && i%100/10==x)
            f++;
        if(i>=100 && i%1000/100==x)
            f++;
        if(i>=1000 && i%10000/1000==x)
            f++;
        if(i>=10000 && i%100000/10000==x)
            f++;
        if(i>=100000 && i%1000000/100000==x)
            f++;
        if(i>=1000000 && i%10000000/1000000==x)
            f++;
        if(i>=10000000 && i%10000000/1000000==x)
            f++;
    }
    cout<<f;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
