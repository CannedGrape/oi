#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    long long n,x,i,sum,t;
    sum=0;
    cin>>n>>x;
    if(n%10>=x&&n%10!=0) sum=1;
    if(n%10<x&&n%10!=0) sum=0;
    t=n%100/10;
    if(t!=0){
        if(t=x) sum=sum+n%100-t*9+1;
        if(t>x) sum=sum+t+10;
        if(t<x) sum=sum+t;
    }
    t=n%1000/100;
    if(t!=0){
        if(t=x) sum=sum+n%1000-t*80+1;
        if(t>x) sum=sum+t+100;
        if(t<x) sum=sum+t;
    }
    t=n%10000/1000;
    if(t!=0){
        if(t=x) sum=sum+n%10000-t*1000+t*280+1;
        if(t>x) sum=sum+t+1000;
        if(t<x) sum=sum+t;
    }
    t=n%100000/10000;
    if(t!=0){
        if(t=x) sum=sum+n%100000-t*10000+t*3520+1;
        if(t>x) sum=sum+t+10000;
        if(t<x) sum=sum+t;
    }
    t=n%1000000/100000;
    if(t!=0){
        if(t=x) sum=sum+n%1000000-t*100000+t*41680+1;
        if(t>x) sum=sum+t+100000;
        if(t<x) sum=sum+t;
    }
    t=n%10000000/1000000;
    if(t!=0){
        if(t=x) sum=sum+n%10000000-t*1000000+t*475120+1;
        if(t>x) sum=sum+t+1000000;
        if(t<x) sum=sum+t;
    }
    cout<<sum<<endl;
    return 0;
}
