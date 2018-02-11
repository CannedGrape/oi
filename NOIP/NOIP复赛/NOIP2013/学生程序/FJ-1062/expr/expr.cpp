#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;
char s[1000000]; int ans=0, t=0, a[10000], b[10000], c[20000]={};
int main(){
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "w", stdout);
    scanf("%s", s);
    for(int i=0; i<strlen(s); i++){
        if(s[i]=='+') ans=(t+ans)%10000, t=0;
        else{
            while(s[i]=='*'){
                 int c=0;
                 for(i++; s[i]>='0'&&s[i]<='9'; i++){
                     c=(c*10+(s[i]-'0'))%10000;
                 }
                 t=(t*c)%10000;
            }
            ans+=t; t=0;
        }
        if(s[i]>='0'&&s[i]<='9') t=(t*10+(s[i]-'0'))%10000;
    }
    printf("%d\n", (ans+t)%10000);
    return 0;
}
