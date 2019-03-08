#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int n,x,sum=0,y;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int y=i;
        while(y>=10){
              if(y%10==x)++sum;
              y/=10;       
        }    
        if(y==x)++sum;
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
