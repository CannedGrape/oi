#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,p;
    cin>>n>>p;
    int a[n],b[n],c[n],i,j,mid=0;
    for(i=0;i<=n-1;i++){
        cin>>a[i];
    }
    for(i=0;i<=n-1;i++){
        b[i]=0;
        c[i]=0;
    }
    b[0]=a[0];
    for(i=1;i<=n-1;i++){
        for(j=0;j<=i;j++){
            b[i]=b[i]+a[j];
        }
    }
    c[0]=b[0];
    mid=c[0];
    for(i=1;i<=n-1;i++){
        c[i]=b[i-1]+c[i-1];
        if(c[i]>mid){
            mid=c[i];
        }
    }
    cout<<mid%p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
