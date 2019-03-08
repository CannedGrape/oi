#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    char a[1000],b[1000],d[10000];
    long long c[10000],i,j,e,g=0,h=1,u,x;
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    gets(a);
    e=strlen(a);
    for(i=0;i<=e-1;i++){
        b[i]=a[e-i-1];
    }
    
    for(i=0;i<=e-1;i++){
        c[i]=0;
    }
    x=0;
    for(i=0;i<=e-1;i++){
        if(b[i]=='+' || b[i]=='*'){
            for(j=x;j<=i-1;j++){
                c[g]=c[g]+b[i]*h;
                for(u=0;u<=0;u++){
                    h=h*10;
                }
            }
            x=i;
            d[g]=b[i];
            g++;
        }
    }
    for(i=0;i<=g;i++){
        if(d[i]=='*'){
            c[i]=c[i]*c[i+1];
            for(j=i+1;j<=g-1;j++){
                c[j]=c[j+1];
            }
            g--;
        }
    }
    for(i=0;i<=g;i++){
        if(d[i]=='+'){
            c[i]=c[i]+c[i+1];
            for(j=i+1;j<=g-1;j++){
                c[j]=c[j+1];
            }
            g--;
        }
    }
    cout<<c[1]+3;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
