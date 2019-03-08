#include<iostream>
#include<cstdio>
using namespace std;

int max1(int i,int j,int k) {
    if(i>j && i>k) return i;
    if(j>k && j>i) return j;
    if(k>j && k>i) return k;
}
int max2(int i,int j) {
    if(i>j) return i;
    return j;
}

int main() {
    int n,p;
    int *a,
        *b,
        *c;
    bool *d;
    int i,j,k,maxn;
    
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    a=new int[1000000];
    b=new int[1000000];
    c=new int[1000000];
    d=new bool[1000000];
    
    scanf("%d%d",&n,&p);
    for(i=0;i<=n-1;i++) scanf("%d",&a[i]);
    for(i=0;i<=n-1;i++) d[i]=false;
    
    b[0]=a[0];
    d[0]=true;
    for(i=1;i<=n-1;i++) {
        if(d[i-1]==true) {
            b[i]=max1(b[i-1],b[i-1]+a[i],a[i]);
            if(b[i]==b[i-1]+a[i] || b[i]==a[i]) d[i]=true;
        }  
        else {
            b[i]=max2(a[i],b[i-1]);
            if(b[i]==a[i]) d[i]=true;
        }
    }
    c[0]=b[0];
    for(i=1;i<=n-1;i++) {
        maxn=c[0]+b[0];
        for(j=0;j<=i-1;j++) {
            if(c[j]+b[j]>maxn) maxn=c[j]+b[j];
        }
        c[i]=maxn;
    }
    maxn=c[0];
    for(i=1;i<=n-1;i++) {
        if(c[i]>maxn) maxn=c[i];                
    }
    
    cout<<maxn%p;
    
    return 0;
}
