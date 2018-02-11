#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int t[20003]={},fen[20003]={};
int p,n,a[20003]={};
int maxf=0,maxs=0;
int max(int x,int y){
    if(x>y)return x;
    else return y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>p;
    for(int i=1;i<=n;i++)cin>>a[i];
    t[1]=a[1];fen[1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            p=t[i];
            t[i]+=max(0,a[j]);
            if(p==t[i]&&a[j]!=0)break;    
        }    
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            maxf=max(maxf,t[j]+fen[j]);         
        }
        fen[i]=maxf;
        maxf=0;    
    }
    for(int i=1;i<=n;i++)
        maxs=max(maxs,fen[i]);
    cout<<maxs<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
