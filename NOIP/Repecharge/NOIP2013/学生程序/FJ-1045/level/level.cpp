#include<iostream>
#include<cstdio>
using namespace std;
int s[1002]={},w[1002]={0},k[1002][1002]={};
int n,m;
int main(){
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>s[i];
        for(int j=1;j<=s[i];j++)cin>>k[s[i]][j];    
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=s[i];j++){
            ++w[k[s[i]][j]];    
        }    
    }
    int max=0;
    for(int i=1;i<=n;i++)if(w[i]>max)max=w[i];
    cout<<max<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
