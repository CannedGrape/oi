#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int x;

int digit(int n) {
    int ret=0;
    do {
        n/=10;
        ret++;
    }while(n>0);
    return ret;
}

int work(int n,int level) {
    int ret=0;
    switch(level) {
    case 0: //1
        if(n>=x) {
            ret=1;
        }
        else {
            ret=0;
        }
        break;
    case 1: //10
        ret=0;
        if(n==0&&x==0) {
            ret+=1;
        }
        if(n/10>x) {
            if(x!=0) ret+=10;
        }
        else if(n/10==x) {
            ret+=n%10+1;
        }
        ret+=work(9,0)*(n/10);
        ret+=work(n%10,0);
        break;
    case 2: //100
        ret=0;
        if(n==0&&x==0) {
            ret+=2;
        }
        if(n/100>x) {
            if(x!=0) ret+=100;
        }
        else if(n/100==x) {
            ret+=n%100+1;
        }
        ret+=work(99,1)*(n/100);
        ret+=work(n%100,1);
        break;
    case 3: //1000
        ret=0;
        if(n==0&&x==0) {
            ret+=3;
        }
        if(n/1000>x) {
            if(x!=0) ret+=1000;
        }
        else if(n/1000==x) {
            ret+=n%1000+1;
        }
        ret+=work(999,2)*(n/1000);
        ret+=work(n%1000,2);
        break;
    case 4: //10000
        ret=0;
        if(n==0&&x==0) {
            ret+=4;
        }
        if(n/10000>x) {
            if(x!=0) ret+=10000;
        }
        else if(n/10000==x) {
            ret+=n%10000+1;
        }
        ret+=work(9999,3)*(n/10000);
        ret+=work(n%10000,3);
        break;
    case 5: //100000
        ret=0;
        if(n==0&&x==0) {
            ret+=5;
        }
        if(n/100000>x) {
            if(x!=0) ret+=100000;
        }
        else if(n/100000==x) {
            ret+=n%100000+1;
        }
        ret+=work(99999,4)*(n/100000);
        ret+=work(n%100000,4);
        break;
    case 6: //1000000
        ret=0;
        if(n==0&&x==0) {
            ret+=6;
        }
        if(n/1000000>x) {
            if(x!=0) ret+=1000000;
        }
        else if(n/1000000==x) {
            ret+=n%1000000+1;
        }
        ret+=work(999999,5)*(n/1000000);
        ret+=work(n%1000000,5);
        break;
    }
    return ret;
}

int main() {
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int n;
    scanf("%d%d",&n,&x);
    int ans=work(n,digit(n)-1);
    if(x==0) {
        ans--;
    }
    printf("%d\n",ans);
}
