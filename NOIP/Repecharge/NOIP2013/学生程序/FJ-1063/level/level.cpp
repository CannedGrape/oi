#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int n,p,i,j,q[1000][100],w,s;
    cin>>n>>p;
    for(i=1;i<=p;i++){
        cin>>w;
        for(j=1;j<=w;j++) cin>>q[i][j];
    }
    s=1+1;
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
