#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,p,i,j;
    long long q,ql;
    cin>>n>>p;
    long long a[n],b[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        b[i]=0;
    }
    for(i=n-1;i>=0;i--){
        q=a[i];
        ql=a[i];
        for(j=i-1;j>=0;j--){
            ql=ql+a[j];
            if(ql>q)
                q=ql;
        }
        a[i]=q;
    }
    b[0]=a[0];
    for(i=1;i<n;i++){
        q=a[i-1]+b[i-1];
        for(j=i-2;j>=0;j--){
            if(a[j]+b[j]>q)
                q=a[j]+b[j];
        }
        b[i]=q;
    }
    sort(b,b+n);
    cout<<b[n-1]%p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
