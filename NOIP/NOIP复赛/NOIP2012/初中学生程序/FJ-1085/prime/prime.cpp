#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool num(int n){
    int i;
    for (i=2; i<=sqrt(n); i++){
        if (n%i==0) return false;
    }
    return true;
}

int main(){
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    
    int n,i,j;
    cin>>n;
    
    for (i=2; i<=sqrt(n); i++){
        j=n/i;
        if (num(i) && num(j) && i!=j){
            cout<<j<<endl;
            break;
        }
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
