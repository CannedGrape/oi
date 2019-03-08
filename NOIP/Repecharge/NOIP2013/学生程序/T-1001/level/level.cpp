#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int a[730][713],i,j,n,m,sum;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>a[i][1];
        for(j=2;j<=a[i][1];j++){
            cin>>a[i][j];
        }
    }
    sum=m+2;
    for(i=1;i<=m;i++){
        for(j=2;j<=a[i][1];j++){
            if(a[i][2]=a[i+1][j]){
                if(a[i][3]=a[i][j+1]){
                    sum=sum-1;
                }
            }
        }
        
    }
    cout<<sum<<endl;
    return 0;
}
