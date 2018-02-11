#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n,p,i,j,beg,ans;
int a[10000];
int b[10000];
int c[10000];
int main(){
    
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>p;
    for(i=0,beg=0,ans=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
        beg=beg+a[i];
        b[i]=beg;
        }        
    }
    
    
    ans=0;
    for(i=0;i<n;i++){
        c[i]=a[i];
        beg=a[i];
        ans=b[i]+c[i];
        if(beg>=ans)
            c[i+1]=beg;
        else
            c[i+1]=ans;
        
    }
    
    cout<<c[n-1]%p<<endl;    
    fclose(stdin);
    fclose(stdout);
    return 0;    
}
