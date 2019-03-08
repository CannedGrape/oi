#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    long long n,x,nq,i,j,h;
    cin>>n>>x;
    int w=1,q=0;
    nq=n;
    while(nq>=10){
        w++;
        nq=nq/10;
    }
    for(i=1;i<=n;i++){
        if(i/10==x) q++;
        for(j=2,h=1;j<=w;j++,h=h*10)
            if(i/h%(h*10)==x) q++;
    }
    cout<<q;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
