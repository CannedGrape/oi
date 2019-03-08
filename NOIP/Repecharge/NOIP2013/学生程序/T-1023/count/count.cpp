#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    long long n,k=0;
    int x,i,j,a,b,c,l;
    cin>>n>>x;
    char m[8];
    for(i=0;i<=n;i++){
        b=i;
        if(i<9&&i==x)
            k++;
        else{    
            for(a=1;a<8;a++){
                c=b%10;
                if(c==x)
                    k++;
                b=b/10;
                              }
             }
    }
    cout<<k<<endl;
    fclose(stdin);
    fclose(stdout);
    system("pause");
    return 0;
    }
